#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  vector<vector<int>> getFactors(int n) {
    vector<vector<int>> ans;     
    vector<int> path;
    dfs(path, ans, n);
    return ans;
  }

  void dfs(vector<int>& path, vector<vector<int>>& ans, int n) {
    int p = path.empty() ? 2 : path.back();
    for (; p<=n/p; ++p) {
      if (n % p == 0) {

        vector<int> tmp = path;
        tmp.push_back(p);
        tmp.push_back(n/p);
        ans.emplace_back(tmp);
        
        path.push_back(p);
        dfs(path, ans, n/p);
        path.pop_back();
      }
    }
  }
  
};
