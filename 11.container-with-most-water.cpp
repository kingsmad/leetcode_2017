#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    const vector<int>& v = height;
    int n = v.size();
    int l = 0, r = n-1, ans = 0;
    while(l < r) {
      ans = max(ans, abs(min(v.at(l), v.at(r)) * (r - l))); 
      if (v.at(l) < v.at(r)) ++l; 
      else --r;
    }

    return ans;
  }
};
