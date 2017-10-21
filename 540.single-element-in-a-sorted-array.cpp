#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int ans = 0;
    for (int d : nums) ans ^= d;
    return ans;
  }
};
