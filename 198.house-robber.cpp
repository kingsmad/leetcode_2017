#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int dp[2];      
    dp[0] = 0, dp[1] = nums[0]; 
    for (int i=1; i<n; ++i) {
      int t1 = max(dp[1], dp[0]);
      int t2 = max(dp[0], dp[0] + nums[i]);
      dp[0] = t1;
      dp[1] = t2;
    }
    return max(dp[0], dp[1]);
  }
};
