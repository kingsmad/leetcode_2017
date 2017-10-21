#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
 public:

   void dfs(int x, vector<vector<int>>& G, vector<int>& ans) { 
     ans.push_back(x);
     for (int d : G[x]) dfs(d, G, ans);
   }

  vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    int n = pid.size();
    vector<vector<int> > G(n+10, vector<int>());
    
    for (int i=0; i<n; ++i) {
      int u = pid.at(i), v = ppid.at(i);
      G[v].push_back(u);
    }

    vector<int> ans;
    dfs(kill, G, ans);
    return ans;
  }
};
