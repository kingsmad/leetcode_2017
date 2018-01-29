#include <unordered_map>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
inline int lowbit(int x) { return x & (-x); }
typedef long long ll;
unordered_map<ll, int> val2id;
int sid = 1;
const int maxn = 5e4 + 10;

class Solution {
  struct FenWickTree {
    int n;
    int c[maxn<<1];
    void init(int nt) {
      n = nt;
      memset(c, 0, sizeof(c));
    }

    void update(int p, int v) {
      for (int i = p; i <= n; i += lowbit(i)) c[i] += v;
    }

    int query(int x) {
      int res = 0;
      for (int i = x; i > 0; i -= lowbit(i)) res += c[i];
      return res;
    }

    int Calc(int x) { return query(n) - query(x); }
  } ftree;

 public:
  int reversePairs(vector<int>& nums) {
    val2id.clear();
    sid = 1;
    vector<ll> buf;
    for (ll d : nums) {
      buf.push_back(d);
      buf.push_back(2 * d);
    }
    sort(buf.begin(), buf.end());
    for (ll d : buf) Val2Id(d);

    ftree.init(2 * nums.size() + 1);
    int ans = 0;
    for (int d : nums) {
      ans += ftree.Calc(Val2Id(1ll*d*2));
      ftree.update(Val2Id(d), 1);
    }
    return ans;
  }

  int Val2Id(ll x) {
    if (val2id.count(x) > 0) return val2id.at(x);
    val2id.emplace(x, sid);
    return sid++;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main() {
  freopen("493.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  vector<int> nums(n, 0);
  for (int i=0; i<n; ++i) scanf("%d", &nums[i]);
  Solution sol;
  int ans = sol.reversePairs(nums);
  return 0 * printf("%d\n", ans);
}
#endif
