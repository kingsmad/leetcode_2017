#include <vector>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k == 0) return 0;
    int n = nums.size(), ans = 0;
    int p = 0, q = 0;
    ll prod = 1;

    for (int i=0; i<n; ++i) {
      if (q <= i) { p = i; q = i; prod = 1;}
      while(p < i) { prod /= nums.at(p); ++p;}
      while(q < n && prod * nums.at(q) < k) { prod *= nums.at(q++);}
      ans += q - i;
    }

    return ans;
  }
};
