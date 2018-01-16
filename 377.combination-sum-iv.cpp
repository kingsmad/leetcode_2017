#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 1e5 + 10;
int n, dp[maxn];;

class Solution {
 public:
  int combinationSum4(vector<int>& nums, int target) {
    n = nums.size();
    memset(dp, -1, sizeof(dp));
    return calc(target, nums);
  }

  int calc(int sum, const vector<int>& nums) {
    if (sum == 0) return 1;
    if (dp[sum] != -1) return dp[sum];

    dp[sum] = 0;
    for (int i=0; i<n; ++i) {
      if (nums.at(i) <= sum) {
        dp[sum] += calc(sum-nums.at(i), nums);
      }
    }
    return dp[sum];
  }

  
};
