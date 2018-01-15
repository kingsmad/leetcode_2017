#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> > ans;

class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    ans.clear();
    dfs(0, 1, k, n);
    return ans;
  }

  void dfs(int state, int p, int k, int n) {
    if (n == 0) {
      if (k != 0) return;
      vector<int> buf;
      for (int i=1; i<10; ++i) {
        if (state & (1<<i)) buf.push_back(i);
      }
      ans.push_back(buf);
      return;
    }

    if (p >= 10 || k <= 0) return;

    dfs(state, p+1, k, n);
    if (k > 0 && n >= p) 
      dfs(state | (1<<p), p+1, k-1, n-p);
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  Solution sol; 
  int k, n; scanf("%d%d", &k, &n);
  vector<vector<int>> ans = sol.combinationSum3(k, n);
  for (int i=0; i<ans.size(); ++i) {
    for (int d : ans.at(i)) printf("%d ", d);
    printf("\n");
  }
  return 0;
}
#endif
