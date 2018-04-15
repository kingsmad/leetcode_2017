#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int p = 0, n = nums.size();
    for (int i=0; i<n; ++i) {
      if (nums[p] == nums[i]) continue;
      nums[++p] = nums[i];
    }
    return p + 1;
  }
};
