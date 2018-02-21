#include <bits/stdc++.h>

using namespace std;
int row, col;
vector<int> fa;
int findset(int x) { return x == fa[x] ? x : fa[x] = findset(fa[x]); }
void join(int x, int y) { fa[findset(x)] = findset(y); }
const int rs[4] = {0, 0, -1, 1};
const int cs[4] = {1, -1, 0, 0};
inline int getsid(int x, int y) { return x * col + y; }

class Solution {
 public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    row = m, col = n;
    set<pair<int, int>> ms;
    fa = vector<int>(m * n, 0);
    vector<int> res;

    int ans = 0;

    for (auto& pr : positions) {
      int x = pr.first, y = pr.second;
      ms.insert({x, y});
      fa[getsid(x, y)] = getsid(x, y);

      // calc previous cc count
      unordered_set<int> tmp;
      for (int z = 0; z < 4; ++z) {
        int nx = x + rs[z], ny = y + cs[z];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && ms.count({nx, ny})) {
          tmp.insert(findset(getsid(nx, ny)));
        }
      }
      int pre_bcc = tmp.size();

      // join them
      for (int z = 0; z < 4; ++z) {
        int nx = x + rs[z], ny = y + cs[z];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && ms.count({nx, ny})) {
          join(getsid(x, y), getsid(nx, ny));
        }
      }
      ans -= pre_bcc - 1;
      res.push_back(ans);
    }

    return res;
  }
};
