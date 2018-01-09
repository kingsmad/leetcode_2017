#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int st = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (st == nums.size() || nums.at(st) != target) return {-1, -1};
    
    int ed = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

    return {st, ed-1};
  }
};
