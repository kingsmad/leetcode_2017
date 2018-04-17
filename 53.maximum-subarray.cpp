#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) return 0;
    int dp = nums[0], ans = nums[0];
    for (int i=1; i<nums.size(); ++i) {
      dp = max(dp+nums[i], nums[i]);
      ans = max(dp, ans); 
    }
    return ans;
  }
};
