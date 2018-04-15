#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
 public:
  int numberOfBoomerangs(vector<pair<int, int>>& points) {
    int n = points.size();
    int ans = 0;

    for (int i=0; i<n; ++i) {
      unordered_map<ll, int> ms;
      for (int j=0; j<n; ++j) {
        if (i != j) {
          ll x = points[i].first - points[j].first;
          ll y = points[i].second - points[j].second;
          ll v =  x * x + y * y;
          ++ms[v];
        }
      }

      for (auto& pr : ms) {
        int cnt = pr.second;
        ans += cnt * (cnt-1);
      }
    }

    return ans;
  }

};
