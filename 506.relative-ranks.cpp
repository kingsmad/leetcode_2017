#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    int n = nums.size();
    vector<int> sids;
    for (int i=0; i<n; ++i) sids.push_back(i);
    sort(sids.begin(), sids.end(), [&](int x, int y) { return nums[x] < nums[y];});

    vector<string> ans(n);
    ans[sids[0]] = "Gold Medal";
    if (n > 1) ans[sids[1]] = "Silver Medal";
    if (n > 2) ans[sids[2]] = "Bronze Medal";
    for (int i=3; i<n; ++i) {
      ans[sids[i]] = to_string(i);
    }

    return ans;
  }
};
