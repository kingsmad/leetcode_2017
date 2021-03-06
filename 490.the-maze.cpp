#include <bits/stdc++.h>
using namespace std;

const int rs[4] = {0, 0, 1, -1};
const int cs[4] = {1, -1, 0, 0};

class Solution {
  int row, col;

 public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
               vector<int>& destination) {
    row = maze.size();
    col = maze.at(0).size();

    queue<pair<int, int>> mq;
    vector<vector<bool>> vis(row + 1, vector<bool>(col + 1, 0));
    mq.push({start[0], start[1]});
    vis[start[0]][start[1]] = 1;

    while (mq.size()) {
      int x = mq.front().first, y = mq.front().second;
      if (x == destination[0] && y == destination[1]) return true;
      mq.pop();

      for (int z = 0; z < 4; ++z) {
        int k = 0;
        while ((k + 1) <= max(row, col)
               && IsValid(x + (k + 1) * rs[z], y + (k + 1) * cs[z], maze))
          ++k;
        int nx = x + k * rs[z];
        int ny = y + k * cs[z];
        if (!vis[nx][ny]) {
          mq.push({nx, ny});
          vis[nx][ny] = 1;
        }
      }
    }

    return false;
  }

  bool IsValid(int x, int y, const vector<vector<int>>& maze) {
    return x >= 0 && x < row && y >= 0 && y < col && !maze[x][y];
  }
};
