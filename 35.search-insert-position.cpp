#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();      
    int l = 0, r = n;
    while(l < r) {
      int md = (l+r) / 2;
      if (nums[md] < target) l = md + 1;
      else r = md;
    }
    return l;
  }
};
