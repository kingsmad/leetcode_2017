#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n;
    int pv = nums.back();
    if (nums.at(l) < nums.back()) return nums.at(l);

    while(l < r) {
      int md = (l+r) / 2;
      if (nums.at(md) > pv) l = md + 1;
      else r = md;
    }

    return nums.at(l);
  }
};
