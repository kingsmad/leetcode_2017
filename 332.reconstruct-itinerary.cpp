#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
const int maxn = 1e5 + 10;

struct Edge {
  int u, v;
};
vector<int> G[maxn];
vector<Edge> edges;

void AddEdge(int u, int v) {
  edges.push_back((Edge){u, v});
  int m = edges.size();
  G[u].push_back(m-1);
}

bool search_done = false;

class Solution {
  map<string, int> str2sid;
  map<int, string> sid2str;
  int sid_sz = 0;
 public:
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    set<string> cities;
    for (auto& p : tickets) { cities.insert(p.first); cities.insert(p.second);}
    Init(cities.size() + 100);

    for (const string& s : cities) LinkSid(s);

    for (auto& p : tickets) AddEdge(Sid(p.first), Sid(p.second));

    // sort the edges in each nodes, this is for dfs
    SortEdges(cities.size());

    vector<bool> vis(edges.size(), false);
    vector<int> path;
    path.push_back(Sid("JFK"));
    search_done = false;

    dfs(Sid("JFK"), vis, path);

    vector<string> res;
    for (int d : path) {
      res.emplace_back(sid2str.at(d)); 
    }
    return res;
  }

  void SortEdges(int n) {
    auto fn = [](int x, int y) { return edges.at(x).v < edges.at(y).v;};
    for (int i=0; i<n; ++i) sort(G[i].begin(), G[i].end(), fn);
  }

  void Init(int n) {
    for (int i=0; i<n; ++i) G[i].clear();
    edges.clear();
    search_done = false;
    str2sid.clear();
    sid2str.clear();
    sid_sz = 0;
  }

  void dfs(int u, vector<bool>& vis, vector<int>& path) {
    if (search_done) return;
    int m = vis.size();

    bool alldone = true;
    for (int i=0; i<m; ++i) if (!vis.at(i)) { alldone = false; break;}

    if (alldone) {
      search_done = true;
      return;
    }

    if (search_done) return;

    for (int i=0; i<G[u].size(); ++i) {
      if (vis[G[u][i]]) continue;
      int v = edges[G[u][i]].v;

      vis[G[u][i]] = true;
      path.push_back(v);

      dfs(v, vis, path);

      if (search_done) return;
      vis[G[u][i]] = false;
      path.pop_back();
    }
  }
  
  void LinkSid(const string& s) {
    if (str2sid.count(s) > 0) return;
    sid2str[sid_sz] = s;
    str2sid[s] = sid_sz; 
    ++sid_sz;
  }

  inline int Sid(const string& s) { return str2sid.at(s);}
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {

}
#endif
