#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int dominantIndex(vector<int>& nums) {
    int mx = INT_MIN;      
    for (int d : nums) mx = max(mx, d);
    for (int d : nums) if (mx != d && mx < d * 2) return -1;

    for (int i=0; i<nums.size(); ++i) if (mx == nums[i]) return i;
  }
};
