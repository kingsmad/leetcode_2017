#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findLengthOfLCIS(vector<int>& nums) {
    int n = nums.size(), ans = 0;
    for (int i=0; i<n; ) {
      int q = i + 1;
      while(q < n && nums[q] > nums[q-1]) ++q;
      ans = max(ans, q-i);
      i = q;
    }

    return ans;
  }
};
