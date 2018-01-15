#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> ans;
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    ans.clear();
    vector<int> path;
    sort(nums.begin(), nums.end());
    dfs(0, path, nums);
    return ans;
  }

  void dfs(int p, vector<int>& path, const vector<int>& nums) {
    int n = nums.size();
    if (p == n) {
      ans.push_back(path);
      return;
    }

    int q = p + 1;
    while(q < n && nums.at(q) == nums.at(p)) ++q;

    int vcnt = 0;
    for (int i=0; i<=q-p; ++i) {
      dfs(q, path, nums);
      path.push_back(nums.at(p));
      ++vcnt;
    }
    while(vcnt--) path.pop_back();
  }
};
