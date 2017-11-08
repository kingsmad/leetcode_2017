#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 10;

int fa[maxn];
int findset(int x) { return (x == fa[x]) ? x : fa[x] = findset(fa[x]);}
void join(int x, int y) {
  int u = findset(x), v = findset(y);
  if (u != v) fa[u] = v;
}

class Solution {
 public:
  int countComponents(int n, vector<pair<int, int>>& edges) {
    for (int i=0; i<n; ++i) fa[i] = i; 
    for (auto& p : edges) join(p.first, p.second);
    
    set<int> ms;
    for (int i=0; i<n; ++i) ms.insert(findset(i));

    return (int)ms.size();
  }
};
