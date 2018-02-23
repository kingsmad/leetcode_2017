#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 10;
const int rs[4] = {0, 0, -1, 1};
const int cs[4] = {1, -1, 0, 0};
map<pair<int, int>, vector<vector<int>>> ms;
int row, col;
class Solution {
 public:
  int shortestDistance(vector<vector<int>>& grid) {
    ms.clear();
    row = grid.size(), col = grid.at(0).size();
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j)
        if (grid[i][j] == 1) { bfs(i, j, grid); }

    int ans = inf;

    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] != 0) continue;
        bool ok = true;
        int cnt = 0;
        for (int x = 0; x < row && ok; ++x) {
          for (int y = 0; y < col && ok; ++y) {
            if (grid[x][y] == 1) {
              int v = ms[{x, y}][i][j];
              if (v == inf) { ok = false; }
              cnt += v;
            }
          }
        }
        ans = min(ans, cnt);
      }
    }

    if (ans == inf) return -1;
    return ans;
  }

  void bfs(int x, int y, const vector<vector<int>>& grid) {
    if (ms.count({x, y}) == 0) {
      ms.emplace(make_pair(x, y),
                 vector<vector<int>>(row + 1, vector<int>(col + 1, inf)));
    }
    vector<vector<int>>& bd = ms[{x, y}];

    queue<pair<int, int>> mq;
    mq.push({x, y});
    bd[x][y] = 0;
    while (mq.size()) {
      int x = mq.front().first, y = mq.front().second;
      mq.pop();
      for (int z = 0; z < 4; ++z) {
        int nx = x + rs[z], ny = y + cs[z];
        if (nx < 0 || nx >= row || ny < 0 || ny >= col || grid[nx][ny] != 0)
          continue;
        if (bd[nx][ny] != inf) continue;
        bd[nx][ny] = bd[x][y] + 1;
        mq.push({nx, ny});
      }
    }

  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  // vector<vector<int>> grid = {{1, 0, 2, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0,
  // 0}};
  vector<vector<int>> grid = {{1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 1},
                              {0, 1, 1, 0, 0, 1}, {1, 0, 0, 1, 0, 1},
                              {1, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 0, 1},
                              {0, 1, 1, 1, 1, 0}};
  Solution sol;
  int ans = sol.shortestDistance(grid);
  return 0 * printf("%d\n", ans);
}
#endif
