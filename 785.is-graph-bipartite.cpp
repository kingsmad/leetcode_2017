#include <bits/stdc++.h>
const int maxn = 110;
using namespace std;

class Solution {
  int G[maxn][maxn];
  int color[maxn];
  int n;
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    memset(G, 0, sizeof(G)); 
    memset(color, 0, sizeof(color));
    n = graph.size();

    for (int i=0; i<n; ++i) {
      for (int d : graph[i]) {
        G[i][d] = G[d][i] = 1;
      }
    }

    for (int i=0; i<n; ++i) {
      if (color[i] == 0 && !dfs(i, 1)) return false;
    }

    return true;
  }

  bool dfs(int u, int c) {
    color[u] = c; 
    for (int i=0; i<n; ++i) {
      if (!G[u][i]) continue;
      if (color[i] == color[u]) return false;
      if (color[i] == 0 && !dfs(i, 3-c)) return false;
    }
    return true;
  }
};
