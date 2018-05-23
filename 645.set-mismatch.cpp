#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    for (int i=0; i<n; ++i) {
      while(1) {
        if (nums[i] == i+1) break;
        int x = nums[i] - 1;
        if (nums[x] == nums[i]) { 
          ans.push_back(nums[x]);
          break;
        }
        swap(nums[x], nums[i]);
      }
    }

    while(ans.size() > 1) ans.pop_back();
    for (int i=0; i<n; ++i) if (nums[i] != i+1) {
      ans.push_back(i+1);
      break;
    }
    return ans;
  }
};
