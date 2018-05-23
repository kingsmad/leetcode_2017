#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    vector<int> dp(n+2, INT_MAX);
    dp[0] = 0;
    for (int i=0; i<=n; ++i) {
      dp[i+1] = min(dp[i+1], dp[i] + cost[i-1]); 
      if (i+2 <= n+1) dp[i+2] = min(dp[i+2], dp[i] + cost[i-1]);
    }
    return dp[n+1];
  }
};
