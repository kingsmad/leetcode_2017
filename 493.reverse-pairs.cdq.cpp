#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define per(i, a, n) for (int i = n - 1; i >= a; --i)
#define rep(i, a, n) for (int i = a; i < n; ++i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
#define lc(o) (o << 1)
#define rc(o) (o << 1 | 1)
ll powmod(ll a, ll b, ll MOD) {
  ll res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
/*----------- head-----------*/

const int maxn = 5e4 + 10;
struct Op {
  int typ, v, res;
};

struct Op ops[2*maxn];

void cdq(int l, int r) {
  if (l+1 >= r) return;
  int md = (l+r) / 2;
  cdq(l, md);

  // brute force
  vector<ll> buf;
  for (int i=l; i<md; ++i) if(ops[i].typ == 1) buf.push_back(ops[i].v);
  sort(buf.begin(), buf.end());

  for (int i=md; i<r; ++i) {
    if (ops[i].typ == 1) continue;
    int p = upper_bound(buf.begin(), buf.end(), 2ll * ops[i].v) - buf.begin();
    ops[i].res += buf.size() - p; 
  }

  cdq(md, r);
}

class Solution {
 public:
  int reversePairs(vector<int>& nums) {
    int sid = 0;
    for (int i=0; i<nums.size(); ++i) {
      struct Op op1, op2;
      op1.typ = 0, op1.v = nums.at(i); op1.res = 0;
      op2.typ = 1, op2.v = nums.at(i); op2.res = 0;
      ops[sid++] = op1;
      ops[sid++] = op2;
    }

    cdq(0, sid);

    ll ans = 0;
    for (int i=0; i<sid; ++i) {
      if (ops[i].typ == 0) ans += ops[i].res;
    }

    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) { 
  freopen("in.txt", "r", stdin); 
  int n; scanf("%d", &n);
  vector<int> nums(n, 0);
  for(int i=0; i<n; ++i) scanf("%d", &nums[i]);
  Solution sol;
  int ans = sol.reversePairs(nums);
  return 0 * printf("%d\n", ans);
}
#endif
