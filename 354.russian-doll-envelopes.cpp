#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int maxn = 1e4 + 10;

struct Query {
  int sid, num, dp;
} qs[maxn];

class Solution {
 public:
  int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    int n = envelopes.size();
    if (n <= 1) return n;
    sort(envelopes.begin(), envelopes.end(),
         [](const pair<int, int>& p1, const pair<int, int>& p2) {
           if (p1.first != p2.first) return p1.first < p2.first;
           return p1.second > p2.second;
         });

    for (int i = 0; i < n; ++i) {
      qs[i].sid = 0;
      qs[i].num = envelopes.at(i).second;
      qs[i].dp = 1;
    }

    cdq(0, n);

    int ans = 1;
    for (int i = 0; i < n; ++i) ans = max(ans, qs[i].dp);
    return ans;
  }

  void cdq(int l, int r) {
    if (l + 1 == r) return;
    int md = (l + r) / 2;
    cdq(l, md);

    vector<int> idxs;
    for (int i = l; i < r; ++i) idxs.push_back(i);

    sort(idxs.begin(), idxs.end(), [&](int x, int y) {
      if (qs[x].num != qs[y].num) return qs[x].num < qs[y].num;
      return x > y;
    });
    int len = 0;
    for (int x : idxs) {
      if (x < md)
        len = max(len, qs[x].dp);
      else
        qs[x].dp = max(qs[x].dp, len + 1);
    }

    cdq(md, r);
  }
};
