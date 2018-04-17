#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int p = 0, n = nums.size();
    for (int i=0; i<n; ++i) {
      if (nums[i] == val) continue;
      nums[p++] = nums[i];
    }
    return p;
  }
};
