#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int climbStairs(int n) {
    int dp[3];
    dp[1] = 1, dp[2] = 2;
    for (int i=3; i<=n; ++i) {
      dp[i%3] = dp[(i-1+3)%3] + dp[(i-2+3)%3];
    }
    return dp[n%3];
  }
};
