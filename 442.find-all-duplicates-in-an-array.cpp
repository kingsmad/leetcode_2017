#include <math.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    for (int i=0; i<n; ++i) {
      int v = abs(nums.at(i));
      if (nums.at(v-1) < 0) ans.push_back(v);
      nums[v-1] = -nums[v-1];
    }

    return ans;
  }
};
