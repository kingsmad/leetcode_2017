#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 10;
int n, c[maxn];
vector<int> G[maxn], topo;
void AddEdge(int u, int v) {
  G[u].push_back(v);
}

void init(int pn) {
  n = pn;
  for (int i=0; i<n; ++i) G[i].clear();
  memset(c, 0, sizeof(c));
}

bool dfs(int u) {
  c[u] = -1;
  for (int v : G[u]) {
    if (c[v] < 0) return false;
    else if (c[v] == 0) if (!dfs(v)) return false;
  }
  c[u] = 1; topo.push_back(u);
  return true;
}

bool toposort() {
  memset(c, 0, sizeof(c));
  topo.clear();
  for (int u=0; u<n; ++u) if (c[u] == 0) {
    if (!dfs(u)) return false;
  }
  reverse(topo.begin(), topo.end());
  return true;
}



class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    init(numCourses);
    for (auto& p : prerequisites) {
      AddEdge(p.second, p.first);
    }
    if (!toposort()) return vector<int>();
    return topo;
  }
};
