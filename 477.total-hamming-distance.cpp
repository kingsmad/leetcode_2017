#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {

    int n = nums.size();
    int ans = 0;
    for (int i=0; i<32; ++i) {
      int zcnt = 0, ocnt = 0;
      for (int d : nums) {
        if (((d & (1<<i)) >> i) > 0) ++ocnt;
        else ++zcnt;
      }
      ans += zcnt * ocnt; 
    }

    return ans;
    
  }
};
