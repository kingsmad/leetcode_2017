#include <set>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

set<vector<int>> ans;

class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    ans.clear();
    vector<int> path;
    dfs(0, path, nums);

    return vector<vector<int>>(ans.begin(), ans.end());
  }

  void dfs(int p, vector<int>& path, vector<int>& nums) {
    if (p == nums.size()) {
      if (path.size() >= 2) ans.insert(path);
      return;
    }

    dfs(p+1, path, nums);
    
    if (path.empty() || path.back() <= nums.at(p)) {
      path.push_back(nums.at(p));
      dfs(p+1, path, nums);
      path.pop_back();
    }
  }
};
