#include <string>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int> > ans;
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    ans.clear();
    int n = nums.size();
    int cap = pow(2, n);

    for (int i=0; i<cap; ++i) {
      vector<int> tmp;
      for (int j=0; j<n; ++j) {
        if (i & (1<<j)) tmp.push_back(nums.at(j));
      }
      ans.push_back(tmp);
    }

    return ans;
  }
};
