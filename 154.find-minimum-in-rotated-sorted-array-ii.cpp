#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int ans = INT_MAX;
    for (int d : nums) ans = min(ans, d);
    return ans;
  }
};
