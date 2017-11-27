#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();    
    multiset<int> ms(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> path;
    
    dfs(ms, path, ans);
    return ans;
  }

  void dfs(multiset<int>& ms, vector<int>& path, vector<vector<int>>& ans) {
    if (ms.empty()) { ans.push_back(path); return;}
    vector<int> tmp(ms.begin(), ms.end());
    for (int i=0; i<tmp.size(); ) {
      int v = tmp.at(i);
      path.push_back(v);
      ms.erase(ms.find(v));
      dfs(ms, path, ans);
      path.pop_back();
      ms.insert(v);

      while(i<tmp.size() && tmp.at(i) == v) ++i;
    }

  }
};
