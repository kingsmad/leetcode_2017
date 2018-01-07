#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int maxn = 1e5 + 10;
int n, c[maxn];
vector<int> G[maxn];
vector<int> topo;
void AddEdge(int u, int v) {
  G[u].push_back(v);
}

bool dfs(int u) {
  c[u] = -1;
  for (int v : G[u]) {
    if (c[v] < 0) return false;
    else if (c[v] == 0) { 
      if (!dfs(v)) return false;
    }
  }
  c[u] = 1; topo.push_back(u);
  return true;
}

bool toposort() {
  topo.clear();
  memset(c, 0, sizeof(c));
  for (int u=0; u<n; ++u) if (c[u] == 0) {
    if (!dfs(u)) return false;
  }
  reverse(topo.begin(), topo.end());
  return true;
}

void init(int pn) {
  n = pn;
  for (int i=0; i<n; ++i) G[i].clear();
}

class Solution {
 public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    init(numCourses); 
    for (auto& p : prerequisites) {
      AddEdge(p.second, p.first);
    }
    if (!toposort()) return false;
    for (int d : topo) cout << d << " ";
    return true;
  }
};
