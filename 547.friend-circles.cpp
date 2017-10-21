#include <set>
#include <vector>
#include <iostream>

using namespace std;

const int maxn = 300;
int fa[maxn];
inline int findset(int x) { return (x == fa[x]) ? x : fa[x]=findset(fa[x]); }
void join(int x, int y ) {
  int u = findset(x), v = findset(y);
  fa[u] = v;
}

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& M) {
    int n = M.size();    
    for (int i=0; i<n; ++i) fa[i] = i;
    for (int i=0; i<M.size(); ++i) for (int j=0; j<M.at(0).size(); ++j) {
      if (M[i][j]) join(i, j);
    }

    set<int> ans;
    for (int i=0; i<n; ++i) ans.insert(findset(i));
    return ans.size();
  }
};
