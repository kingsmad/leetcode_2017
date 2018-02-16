#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    for (int i=0; i<n; ) {
      int mx = nums.at(i);
      for (int j=i+1; j<n; ++j) {
        if (nums.at(i) < nums.at(j) && mx > nums.at(j)) return true; 
        mx = max(mx, nums.at(j));
      }
      int v = nums.at(i);
      while(i < n && nums.at(i) >= v) ++i;
    }

    return false;
  }
};
