#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> lexicalOrder(int n) {
    vector<int> ans;
    for (int i=1; i<10; ++i) dfs(i, ans, n);

    return ans;
  }

  void dfs(int x, vector<int>& ans, const int n) {
    if (x > n) return;
    ans.push_back(x);
    for (int i=0; i<10; ++i) dfs(x*10+i, ans, n);
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int ,char**) {
  int n; scanf("%d", &n);
  Solution sol;
  vector<int> ans = sol.lexicalOrder(n);
  for (int d : ans) printf("%d ", d);
  return 0;
}
#endif
