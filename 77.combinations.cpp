#include <iostream>
#include <vector>
using namespace std;
class Solution {
  vector<vector<int>> ans;
  int _n;
 public:
  vector<vector<int>> combine(int n, int k) {
    ans.clear();
    _n = n;
    dfs(0, 1, k); 
    return ans;
  }

  void dfs(uint64_t state, int p, int r) {
    if (r == 0) {
      vector<int> tmp;
      for (int i=1; i<=_n; ++i) if (state & (1<<i)) tmp.push_back(i);
      ans.push_back(tmp);
      return;
    }
    if (p == _n+1) return;
    
    dfs(state|(1<<p), p+1, r-1);
    dfs(state, p+1, r);
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  int n, k; scanf("%d%d", &n, &k); 
  Solution sol;
  vector<vector<int>> ans = sol.combine(n, k);
  for (const vector<int>& v : ans) {
    for (int d : v) { printf("%d ", d); }
    printf("\n");
  }

  return 0;
}

#endif
