#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findShortestSubArray(vector<int>& nums) {
    int n = nums.size();
    map<int, int> ms;      
    for (int d : nums) ++ms[d];
    int mx = 0;
    for (auto& pr : ms) mx = max(mx, pr.second);
    
    if (mx == 1) return 1;

    map<int, vector<int>> ms1;
    for (int i=0; i<n; ++i) {
      if (ms[nums[i]] != mx) continue;
      if (ms1.count(nums[i]) == 0) {
        ms1.emplace(nums[i], vector<int>());
      }
      vector<int>& vc = ms1[nums[i]]; 
      while(vc.size() > 1) vc.pop_back();
      vc.push_back(i);
    }

    int ans = INT_MAX;
    for (auto& pr : ms1) {
      const vector<int>& vc = pr.second;
      ans = min(ans, vc[1] - vc[0] + 1);
    }

    return ans;
  }
};
