#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    int cnt = 0, n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ) {
      int x = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + k) -
              nums.begin();
      if (x >= 0 && x < n && nums[x] == nums[i] + k) ++cnt;

      int p = i + 1;
      while(p < n && nums[p] == nums[i]) ++p;
      i = p;
    }
    return cnt;
  }
};
