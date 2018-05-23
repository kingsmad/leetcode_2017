#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int tot = 0, n = nums.size(); 
    if (n == 0) return -1;
    for (int d : nums) tot += d;

    int sum = 0;
    for (int i=0; i<n; ++i) {
      if ((tot-nums[i]) % 2 == 0 && sum == (tot-nums[i])/2) return i;
      sum += nums[i];
    }
    return -1;
     
  }
};
