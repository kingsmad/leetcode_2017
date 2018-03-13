#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    int l = 0, q = 0;
    double tot = 0;
    int n = nums.size();
    double ans = INT_MIN;
    for (int i = 0; i+k<=n; ++i) {
      while (l < i) { tot -= nums.at(l++); }
      while (q < i + k) tot += nums.at(q++);
      ans = max(ans, tot * 1.0 / k);
    }

    return ans;
  }
};
