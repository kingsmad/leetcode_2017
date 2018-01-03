#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int n = nums.size();     
    int l = 0, r = n; 
    while(l < r) {
      int md = (l+r) / 2;
      if (md + 1 < n && nums.at(md) < nums.at(md+1)) l = md + 1; 
      else r = md;
    }
    return l;
  }
};
