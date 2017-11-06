#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size(); 
    if (n < 2) return n;

    int dir = 0, cnt = n;

    for (int i=1; i<n; ++i) {
      if (nums[i] == nums[i-1]) --cnt;
      else if (nums[i] > nums[i-1]) dir == 1 ? --cnt : dir = 1;
      else dir == -1 ? --cnt : dir = -1;
    }

    return cnt;
  }

};
