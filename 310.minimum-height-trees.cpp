#include <queue>
#include <cstring>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e4 + 10;

int cnt[maxn];
vector<int> G[maxn];
void AddEdge(int u, int v) {
  ++cnt[u], ++cnt[v];
  G[u].push_back(v);
  G[v].push_back(u);
}

void RemoveEdge(int u, int v) {
  --cnt[u], --cnt[v];
}


class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    memset(cnt, 0, sizeof(cnt));
    for (auto& p : edges) {
      AddEdge(p.first, p.second);
    }

    auto fn = [&](int x, int y) { 
      if (cnt[x] != cnt[y]) return cnt[x] < cnt[y];
      return x < y;
    };
    set<int, decltype(fn)> ms(fn);

    for(int i=0; i<n; ++i) ms.insert(i);

    while(!ms.empty()) {
      auto it = ms.begin();
      while(cnt[*it] <= 1) ++it;
      
      vector<int> tmp(ms.begin(), it);

      for (int d : tmp) {
        for (int v : G[d]) RemoveEdge(v, d); 
      }

      for (int d : tmp) ms.erase(d);
    }
    
  }
};
