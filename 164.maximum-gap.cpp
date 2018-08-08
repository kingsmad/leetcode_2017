#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maximumGap(vector<int>& nums) {
    sort(nums.begin(), nums.end());    
    int n = nums.size();
    int ans = 0;
    for (int i=0; i+1<n; ++i) {
      ans = max(ans, nums[i+1] - nums[i]);
    }
    return ans;
  }
};
