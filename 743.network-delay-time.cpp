#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define per(i,a,n) for(int i=n-1;i>=a;--i)
#define rep(i,a,n) for(int i=a;i<n;++i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
#define lc(o) (o<<1)
#define rc(o) (o<<1|1)
ll powmod(ll a,ll b, ll MOD) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
/*----------- head-----------*/



using namespace std;

const int maxn = 5e4 + 10;
const ll inf = 2e9 + 10;

struct Edge {
  int from, to, dist; 
};

struct HeapNode {
  int d, u; 
  bool operator<(const HeapNode& rhs) const {
    return d > rhs.d;
  }
};

struct Dijkstra {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  bool done[maxn];
  int d[maxn], p[maxn]; 
  
  void init(int n) {
    this->n = n;
    for (int i=0; i<n; ++i) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int dist) {
    edges.push_back((Edge){from, to, dist});
    m = edges.size();
    G[from].push_back(m-1);
  }

  void dijkstra(int s) {
    priority_queue<HeapNode> mq; 
    for (int i=0; i<n; ++i) d[i] = inf;
    d[s] = 0;
    memset(done, 0, sizeof(done));
    mq.push((HeapNode){0, s});
    while(mq.size()) {
      HeapNode x = mq.top(); mq.pop();
      int u = x.u;
      if (done[u]) continue;
      done[u] = true;
      for (int i=0; i<G[u].size(); ++i) {
        struct Edge& e = edges[G[u][i]];
        if (d[e.to] > d[u] + e.dist) {
          d[e.to] = d[u] + e.dist;
          p[e.to] = G[u][i];
          mq.push((HeapNode){d[e.to], e.to});
        }
      }
    }
  }
};

class Solution {
  struct Dijkstra dijkstra;
 public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    dijkstra.init(N);
    for (const vector<int>& v : times) {
      dijkstra.AddEdge(v.at(0)-1, v.at(1)-1, v.at(2));
    }
    dijkstra.dijkstra(K-1);
    int ans = 0;
    for (int i=0; i<N; ++i) ans = max(ans, dijkstra.d[i]);
    if (ans == inf) ans = -1;
    return ans;
  }
};
