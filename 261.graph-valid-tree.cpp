#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1e5 + 10;
int n, pa[maxn];
inline int findset(int x) { return x==pa[x] ? x : pa[x]=findset(pa[x]);}
void join(int x, int y) {
  int u = findset(x), v = findset(y);
  if (u == v) return;
  pa[u] = v;
}


class Solution {
 public:
  bool validTree(int n, vector<pair<int, int>>& edges) {
    if (edges.size() != n-1) return false;
    for (int i=0; i<n; ++i) pa[i] = i; 
    for (auto& p : edges) {
      join(p.first, p.second);
    }

    int t = findset(0);
    for (int i=1; i<n; ++i) if (findset(i) != t) return false;
    return true;
  }
};
