#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());      
    int v1 = nums[0] * nums[1] * nums.back();
    int v2 = nums[n-1] * nums[n-2] * nums[n-3];
    return max(v1, v2);
  }
};
