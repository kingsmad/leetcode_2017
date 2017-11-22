#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return;

    int q = n - 1;
    while(q > 0 && nums.at(q) <= nums.at(q-1)) --q;

    reverse(nums.begin() + q, nums.end());

    if (q != 0) {
      int p = q;
      while(p < n && nums.at(p) <= nums.at(q-1)) ++p;
      swap(nums[q-1], nums[p]);
    }
  }
};
