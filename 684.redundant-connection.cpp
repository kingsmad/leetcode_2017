#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 1e3 + 10;

int fa[maxn];
inline int findset(int x) { return fa[x] == x ? x : fa[x] = findset(fa[x]); }
int join(int x, int y) {
  int u = findset(x), v = findset(y);
  if (u == v) return 1;
  fa[u] = v;
  return 0;
}

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    for (int i = 0; i < maxn; ++i) fa[i] = i;

    int au = -1, av = -1;
    for (int i = 0; i < edges.size(); ++i) {
      if (join(edges[i][0], edges[i][1]) == 1) {
        au = edges[i][0], av = edges[i][1];
      }
    }

    return {min(au, av), max(au, av)};
  }
};
