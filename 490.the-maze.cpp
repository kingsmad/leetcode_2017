#include <cstring>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
const int maxn = 110;
const int rs[4] = { 0, 0, 1, -1};
const int cs[4] = {1, -1, 0, 0};

bool vis[maxn][maxn];
int dx, dy, row, col;

class Solution {
 public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
               vector<int>& destination) {
    memset(vis, 0, sizeof(vis));
    row = maze.size(), col = maze.at(0).size();
    dx = destination.at(0), dy = destination.at(1);
    return Dfs(start.at(0), start.at(1), maze);
  }

  inline bool Legal(int x, int y) {
    return !(x < 0 || x >= row || y < 0 || y >= col); 
  }

  bool Dfs(int x, int y, const vector<vector<int>>& maze) {
    if (Legal(x, y) || vis[x][y] ) return false;
    if (x == dx && y == dy) return true;

    vis[x][y] = 1; 

    for (int i=0; i<4; ++i) {
      int k = 1; 
      while(Legal(x + k * rs[i], y + k * cs[i]) && !maze[x+k*rs[i]][y+k*cs[i]]) {
        if (dx == x + k * rs[i] && dy == y + k * cs[i]) return true;
        ++k;
      }
      
      int nx = x + k * rs[i], ny = y + k * cs[i];
      if (Dfs(nx, ny, maze)) return true;
    }

    return false;
  }
};
