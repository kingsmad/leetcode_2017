#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int mx = 0, n = nums.size();
    for (int i=0; i<=mx && i<n; ++i) {
      mx = max(mx, nums.at(i) + i);
    }
    return mx >= n-1;
  }
};
