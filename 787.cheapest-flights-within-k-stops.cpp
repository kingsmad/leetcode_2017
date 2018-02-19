#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9 + 10;
const int maxn = 1e4 + 10;
struct Edge {
  int from, to, dist;
};

struct HeapNode {
  int u, d, k;
  bool operator<(const HeapNode& rhs) const {
    return d > rhs.d;
  }
};

struct Dijkstra {
  int n, m, d[maxn];
  bool done[maxn];
  vector<Edge> edges;
  vector<int> G[maxn];

  void init(int tn) {
    n = tn;
    for (int i=0; i<n; ++i) G[i].clear();
    edges.clear();
  }

  void AddEdge(int u, int v, int dist) {
    edges.push_back((Edge){u, v, dist});
    m = edges.size();
    G[u].push_back(m-1);
  }

  void dijkstra(int s, int k) {
    priority_queue<HeapNode> mq;
    for (int i=0; i<n; ++i) d[i] = inf;
    memset(done, 0, sizeof(done));
    d[s] = 0;
    mq.push((HeapNode){s, 0, 0});
    while(!mq.empty()) {
      HeapNode o = mq.top();
      mq.pop();
      int u = o.u;

      if (done[u]) continue;
      done[u] = true;

      for (int x : G[u]) {
        Edge& e = edges[x];
        if (d[e.to] > d[u] + e.dist && o.k <= k) {
          d[e.to] = d[u] + e.dist;
          mq.push((HeapNode){e.to, d[e.to], o.k+1});
        }
      }
    }
  }

  
} g;

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int K) {
    g.init(n);  
    for (const vector<int>& v : flights) {
      g.AddEdge(v[0], v[1], v[2]);
    }

    g.dijkstra(src, K); 
    if (g.d[dst] != inf) return g.d[dst];
    return -1;
  }
};
