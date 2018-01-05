#include <vector>
#include <iostream>

using namespace std;
const int maxn = 1e5 + 10;
int n, dp[210][maxn];

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    n = nums.size();
    int sum = 0; for (int d: nums) sum += d;
    if (sum & 1) return false;

    for (int j=0; j<sum+1; ++j) dp[0][j] = false;
    dp[0][nums.at(0)] = true;

    for (int i=1; i<n; ++i)  {
      for (int j=0; j<sum/2+1; ++j) {
        if (dp[i-1][j]) dp[i][j] = true;
        else if (j >= nums.at(i) && dp[i-1][j-nums.at(i)]) dp[i][j] = true;
        else dp[i][j] = false;
      }
    }

    return dp[n-1][sum/2];
  }
};

