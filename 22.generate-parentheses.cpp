#include <vector>
#include <string>
using namespace std;

class Solution {
  vector<string> ans;
 public:
  vector<string> generateParenthesis(int n) {
    ans.clear();
    string path;
    
    dfs(path, 0, n, n);
    return ans; 
  }

  void dfs(string& path, int v, int lcnt, int rcnt) {
    if (lcnt == 0 && rcnt == 0) {
      if (v == 0) ans.push_back(path);
      return;
    }

    if (v > 0) {
      path.push_back(')');
      if (rcnt > 0) dfs(path, v-1, lcnt, rcnt-1);
      path.pop_back();
    }

    path.push_back('(');
    if (lcnt > 0) dfs(path, v+1, lcnt-1, rcnt);
    path.pop_back();
  }
};
