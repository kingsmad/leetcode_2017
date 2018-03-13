#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    vector<int> vec;

    vector<int> b = nums;
    sort(b.begin(), b.end());

    for (int i=0; i<n; ++i) {
      if (nums[i] != b[i]) vec.push_back(i);
    }

    if (vec.size() == 0) return 0;
    if (vec.size() == 1) return 2;
    
    return vec.back() + 1 - vec.front();
  }
};
