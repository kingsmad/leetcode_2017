#include <bits/stdc++.h>
using namespace std;
const int maxn = 1100;
int fa[maxn];
struct Topo {
  int n, G[maxn][maxn], c[maxn];
  vector<int> topo;
  void init(int tn) {
    n = tn;
    memset(G, 0, sizeof(G));
    topo.clear();
  }

  bool toposort() {
    topo.clear();
    memset(c, 0, sizeof(c));
    for (int i=1; i<=n; ++i) {
      if (!c[i] && !dfs(i)) {
        int x = topo.front();
        while(topo.size() && G[x][topo.back()] == 0) topo.pop_back();
        reverse(topo.begin(), topo.end());
        return false;
      }
    }
    return true;
  }

  bool dfs(int u) {
    c[u] = -1;
    for (int v=1; v<=n; ++v) if (G[u][v]) {
      if (c[v] < 0 || (!c[v] && !dfs(v))) {
        topo.push_back(u);
        c[u] = 1;
        return false;
      }
    }
    c[u] = 1;
    return true;
  }

  void AddEdge(int x, int y) {
    G[x][y] = 1;
  }
} g;

class Solution {
 public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = -1;    
    for (const vector<int>& vec : edges) for (int d : vec) n = max(d, n);

    g.init(n);

    memset(fa, 0, sizeof(fa));

    // check if there exist one node that has two parents
    int p1 = -1, p2 = -1, ch = -1;
    for (const vector<int>& vec : edges) {
      g.AddEdge(vec[0], vec[1]);
      if (fa[vec[1]] != 0) {
        p1 = fa[vec[1]], p2 = vec[0], ch = vec[1];
      } else {
        fa[vec[1]] = vec[0];
      }
    }

    // if two parents exists, then answer must be one of the two edges, the 
    // answer is either the edge in a cycle (if there is one) or the last one
    if (p1 != -1) {
      if (g.toposort()) return {p2, ch};
      vector<int>& cycle = g.topo;
      int d = -1;
      for (int i=0; i<cycle.size(); ++i) {
        if (cycle[i] == p1 || cycle[i] == p2) d = cycle[i];
      }
      assert(d != -1);
      return {d, ch};
    }

    // no double parents, then check the edge that came at the end 
    g.toposort();
    vector<int>& cycle = g.topo;
    set<pair<int, int>> ms;
    for (int i=0; i<cycle.size(); ++i) ms.emplace(cycle[i], cycle[(i+1)%cycle.size()]);

    for (int i=edges.size()-1; i>=0; --i) {
      int u = edges[i][0], v = edges[i][1];
      if (ms.count({u, v}) > 0) return {u, v};
    }
    return {-1, -1};
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  //vector<vector<int>> edges = {{1,2}, {1, 3}, {2, 3}};
  //vector<vector<int>> edges = {{2,1},{3,1},{4,2},{1,4}};
  //vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 1}, {4, 1}};
  vector<vector<int>> edges = {{4,2}, {1, 5}, {5, 2}, {5, 3}, {2, 4}};
  
  Solution sol;
  vector<int> ans = sol.findRedundantDirectedConnection(edges);
  for (int d : ans) printf("%d ", d);
  printf("\n");
  return 0;
}
#endif
