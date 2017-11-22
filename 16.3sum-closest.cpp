#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();      
    sort(nums.begin(), nums.end());

    int ans = nums.at(0) + nums.at(1) + nums.at(2);
    for (int i=0; i+2<n; ++i) {
      int rtgt = target - nums.at(i); 
      int p = i+1, q = n-1;
      while(p < q) {
        if (abs(nums.at(p) + nums.at(q) + nums.at(i) - target) 
            < abs(ans - target)) {
          ans = nums.at(p) + nums.at(q) + nums.at(i);    
        }
        if (nums.at(p) + nums.at(q) < rtgt) ++p;
        else --q;
      }
    }

    return ans;
    
  }
};
