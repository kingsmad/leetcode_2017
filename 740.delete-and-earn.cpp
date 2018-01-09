#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    map<int, int> ms;
    for (int i=0; i<nums.size(); ++i) ms[nums.at(i)] += nums.at(i);

    sort(nums.begin(), nums.end());
    int n = unique(nums.begin(), nums.end()) - nums.begin();
    if (n == 0) return 0;
    
    vector<int> dp(n+1, 0);
    dp[0] = 0, dp[1] = ms[nums.at(0)];
    for (int i=2; i<n+1; ++i) {
      if (nums.at(i-1) == nums.at(i-2) + 1) 
        dp[i] = max(dp[i-1], dp[i-2] + ms[nums.at(i-1)]); 
      else 
        dp[i] = dp[i-1] + ms[nums[i-1]];
    }

    return dp[n];
  }
};
