#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int maxDistance(vector<vector<int>>& arrays) {
    int mi = arrays[0].front(), mx = arrays[0].back();
    int ans = 0;
    for (int i=1; i<arrays.size(); ++i) {
      const vector<int>& vc = arrays.at(i);
      ans = max(ans, max(vc.back() - mi, mx - vc.front()));
      mi = min(mi, vc.front());
      mx = max(mx, vc.back());
    }
    return ans;
  }
};
