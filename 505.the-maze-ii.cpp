#include <bits/stdc++.h>
using namespace std;
const int rs[4] = {0, 0, 1, -1};
const int cs[4] = {1, -1, 0, 0};

struct Node {
  int x, y, k;
  Node(int x1, int y1, int k1) : x(x1), y(y1), k(k1) {}
  bool operator<(const Node& rhs) const { return k < rhs.k; }
};

class Solution {
  int row, col;

 public:
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
                       vector<int>& destination) {
    row = maze.size();
    col = maze.at(0).size();

    queue<pair<int, int>> mq;
    vector<vector<int>> vis(row + 1, vector<int>(col + 1, -1));
    mq.push({start[0], start[1]});
    vis[start[0]][start[1]] = 0;

    while (mq.size()) {
      int x = mq.front().first, y = mq.front().second;
      mq.pop();
      //if (x == destination[0] && y == destination[1]) return vis[x][y];

      for (int z = 0; z < 4; ++z) {
        int k = 0;
        while ((k + 1) <= max(row, col)
               && IsValid(x + (k + 1) * rs[z], y + (k + 1) * cs[z], maze))
          ++k;
        int nx = x + k * rs[z];
        int ny = y + k * cs[z];
        if (vis[nx][ny] == -1 || vis[nx][ny] > k + vis[x][y]) { 
          vis[nx][ny] = k + vis[x][y];
          mq.push({nx, ny});
        }
      }
    }

    return vis[destination[0]][destination[1]];
  }

  bool IsValid(int x, int y, const vector<vector<int>>& maze) {
    return x >= 0 && x < row && y >= 0 && y < col && !maze[x][y];
  }
};
