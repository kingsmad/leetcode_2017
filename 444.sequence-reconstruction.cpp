#include <bits/stdc++.h>
const int maxn = 1e4 + 10;
using namespace std;

int n, m, c[maxn], indeg[maxn];;
vector<int> G[maxn];
vector<int> topo;
bool dfs(int u) {
  c[u] = -1;  
  for (int v : G[u]) {
    if (c[v] < 0) return false;
    else if (!c[v] && !dfs(v)) return false;
  }
  c[u] = 1;
  topo.push_back(u);
  return true;
}

bool toposort() {
  topo.clear();
  for (int i=1; i<=n; ++i) {
    if (c[i] == 0 && !dfs(i)) return false;
  }
  reverse(topo.begin(), topo.end());
  return true;
}

void AddEdge(int u, int v) {
  G[u].push_back(v);
  ++indeg[v];
}

void Init(int tn) {
  n = tn;
  memset(c, 0, sizeof(c));
  memset(indeg, 0, sizeof(indeg));
  topo.clear();
  for (int i=1; i<=n; ++i) G[i].clear();
}


class Solution {
 public:
  bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    int n = org.size();

    // corner case for [1] [[], []]
    bool ok = false;
    for (int i=0; i<seqs.size(); ++i) for (int j=0; j<seqs[i].size(); ++j) {
      if (seqs[i][j] == n) { ok = true; break;}
      if (seqs[i][j] > n || seqs[i][j] < 1) return false;
    }
    if (!ok) return false;

    Init(n);
    for (const vector<int>& vec : seqs) {
      for (int i=0; i+1<vec.size(); ++i) {
        AddEdge(vec[i], vec[i+1]);
      }
    }
    if (!check_deg()) return false;
    if (!toposort()) return false;

    for (int i=0; i<n; ++i) if (org[i] != topo[i]) return false;
    return true;
  }

  bool check_deg() {
    int cnt = 0;
    for (int i=1; i<=n; ++i) if (G[i].empty()) ++cnt;
    if (cnt > 1) return false;

    cnt = 0;
    for (int i=1; i<=n; ++i) if (indeg[i] == 0) ++cnt;
    if (cnt > 1 ) return false;
    return true;
  }
};
