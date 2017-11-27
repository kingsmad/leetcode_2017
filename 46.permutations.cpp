#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    set<int> ms; 
    int n = nums.size();
    for (int d: nums) ms.insert(d);

    vector<int> path;
    vector<vector<int> > ans;
    dfs(ms, path, ans);

    return ans;
  }

  void dfs(set<int>& ms, vector<int>& path, vector<vector<int>>& ans) {
    if (ms.empty()) { ans.push_back(path); return;}
    vector<int> tmp(ms.begin(), ms.end());
    for (int d : tmp) {
      ms.erase(d);
      path.push_back(d);
      dfs(ms, path, ans);
      path.pop_back();
      ms.insert(d);
    }
  }
};
