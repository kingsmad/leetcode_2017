#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    int n = nums.size();
    vector<int> buf = nums;
    sort(buf.begin(), buf.end());
    vector<int> rank;
    for (int i = 0; i < n; ++i) {
      rank.push_back(
          n - (lower_bound(buf.begin(), buf.end(), nums[i]) - buf.begin()));
    }

    vector<string> ans;
    for (int r : rank) {
      if (r == 1)
        ans.push_back("Gold Medal");
      else if (r == 2)
        ans.push_back("Silver Medal");
      else if (r == 3)
        ans.push_back("Bronze Medal");
      else
        ans.push_back(to_string(r));
    }
    return ans;
  }
};
