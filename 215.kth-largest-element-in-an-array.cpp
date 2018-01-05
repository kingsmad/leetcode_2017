#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end(), greater<int>());
    return nums.at(k-1);
  }
};
