#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int maxn = 5e4 + 10;
inline int lowbit(int x) { return x & (-x); }
struct BIT {
  int n, c[maxn << 1];
  void update(int p, int v) {
    for (int i = p; i <= n; i += lowbit(i)) c[i] += v;
  }

  void init(int tn) {
    n = tn;
    memset(c, 0, sizeof(c));
  }

  ll query(int p) {
    ll res = 0;
    for (int i = p; i > 0; i -= lowbit(i)) res += c[i];
    return res;
  }

  inline ll query(int l, int r) { return query(r) - query(l); }
};

class Solution {
  BIT ftree;
  unordered_map<ll, int> msid;
  int sid = 1;
 public:
  vector<int> countSmaller(vector<int>& nums) {
    sid = 1; 
    int n = nums.size();
    ftree.init(n);

    // get sids
    vector<int> buf = nums;
    sort(buf.begin(), buf.end());
    for (int d : buf) getSid(d);

    vector<int> ans(n, 0);
    for (int i=n-1; i>=0; --i) {
      int x = getSid(nums.at(i));
      ans[i] = ftree.query(x-1);
      ftree.update(x, 1);
    }

    return ans;
  }

  int getSid(ll x) {
    if (!msid.count(x)) msid.emplace(x, sid++);
    return msid.at(x);
  }
};
