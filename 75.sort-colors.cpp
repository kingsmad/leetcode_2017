#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int n = nums.size();
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int d : nums) {
      if (d == 0) ++cnt0;
      else if (d == 1) ++ cnt1;
      else ++cnt2;
    }

    for (int i=0; i<cnt0; ++i) nums[i] = 0;
    for (int i=cnt0; i<cnt0+cnt1; ++i) nums[i] = 1;
    for (int i=cnt0+cnt1; i<n; ++i) nums[i] = 2;
  }
};
