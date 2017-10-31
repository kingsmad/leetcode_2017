#include <iostream>
#include <map>
#include <random>
#include <vector>

using namespace std;
class Solution {
  vector<int> num;
 public:
  Solution(vector<int> nums) {
    num = nums;
  }

  int pick(int target) {
    int cnt = 0, res = -1;
    for (int i=0; i<num.size(); ++i) {
      int d = num.at(i);
      if (d != target) continue;
      ++cnt;
      if (rand() % cnt == 0) res = i;
    }
    return res;
  }

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
