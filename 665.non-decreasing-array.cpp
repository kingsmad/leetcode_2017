#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    int n = nums.size(), p = -1, cnt = 0;
    for (int i=0; i+1<n; ++i) {
      if (nums[i] > nums[i+1]) {
        ++cnt;
        p = i;
      }
    }
    if (cnt == 0) return true;
    if (cnt > 1) return false;
    if (p == -1 || p == n-2) return true;
    
    int v = min(nums[p], nums[p+1]);
    if (v >= nums[p-1] && v <= nums[p+2]) return true;
    v = max(nums[p], nums[p+1]);
    if (v >= nums[p-1] && v <= nums[p+2]) return true;

    return false;
  }
};
