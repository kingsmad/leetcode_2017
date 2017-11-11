#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int maxn = 1e5 + 10;

int dp[maxn];

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return nums.size();

    dp[0] = 1;
    for (int i=1; i<n; ++i) {
      dp[i] = 1;
      for (int j=0; j<i; ++j) {
        if (nums.at(j) < nums.at(i)) dp[i] = max(dp[i], dp[j] + 1);
      }
    }

    int ans = 1;
    for (int i=0; i<n; ++i) ans = max(ans, dp[i]);

    return ans;
  }
};
