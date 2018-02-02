#include <iostream>
#include <vector>
#include <cstring>
const int maxn = 1e3 + 10;
const int inf = 2e9 + 7;

using namespace std;

class Solution {
 public:
  int minCostII(vector<vector<int>>& costs) {
    if (costs.empty()) return 0;
    int n = costs.size(), m = costs.at(0).size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0] = costs[0];
    for (int i=1; i<n; ++i) {
      int mpos = 0;
      for (int j=0; j<m; ++j) if (dp[i-1][j] < dp[i-1][mpos]) mpos = j;
      
      for (int j=0; j<m; ++j) {
        if (j != mpos) dp[i][j] = dp[i-1][mpos] + costs[i][j];
        else {
          dp[i][j] = inf;
          for (int z=0; z<m; ++z) if (z != j) 
            dp[i][j] = min(dp[i][j], dp[i-1][z] + costs[i][j]);
        }
      }
    }

    int ans = inf;
    for (int j=0; j<m; ++j) ans = min(ans, dp[n-1][j]);
    return ans;
  }
};
