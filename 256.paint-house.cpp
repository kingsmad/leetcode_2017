#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minCost(vector<vector<int>>& costs) {
    int n = costs.size();
    if (n == 0) return 0;
    int col[3];    
    for (int i=0; i<3; ++i) col[i] = costs[0][i];
    
    for (int i=1; i<n; ++i) {
      vector<int> tmp(3, 0);
      for (int j=0; j<3; ++j) {
        tmp[j] = min(col[(j+1)%3], col[(j+2)%3]) + costs[i][j];
      }
      for (int j=0; j<3; ++j) col[j] = tmp[j];
    }

    int ans = col[0];
    for (int i=1; i<3; ++i) ans = min(ans, col[i]);
    return ans;
  }
};
