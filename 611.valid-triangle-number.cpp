#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i=0; i<n; ++i) {
      for (int j=i+1; j<n; ++j) {
        int p = lower_bound(nums.begin(), nums.end(), \
            nums.at(i) + nums.at(j)) - nums.begin();
        if (p > j) ans += p - j - 1;
      }
    }

    return ans;
  }
};
