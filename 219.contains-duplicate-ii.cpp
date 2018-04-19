#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> v2p;
    for (int i=0; i<n; ++i) {
      if (v2p.count(nums[i]) > 0) {
        int pre = v2p.at(nums[i]);
        if (i - pre <= k) return true;
      } 
      v2p[nums[i]] = i;
    }
    return false;
  }
};
