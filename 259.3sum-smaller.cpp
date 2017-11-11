#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int threeSumSmaller(vector<int>& nums, int target) {
    int cnt = 0, n = nums.size();

    for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) for(int z=j+1; z<n; ++z) {
      if (nums.at(i) + nums.at(j) + nums.at(z) < target) ++cnt;
    }

    return cnt;
  }
};
