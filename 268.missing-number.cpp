#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    for (int i=0; i<n; ++i) {
      while(1) {
        if (nums[i] == i) break;
        if (nums[i] < 0 || nums[i] >= n) break;
        if (nums[nums[i]] == nums[i]) break;
        swap(nums[i], nums[nums[i]]);
      }
    }

    for (int i=0; i<n; ++i) if (nums[i] != i) return i;
    return n;
  }
};
