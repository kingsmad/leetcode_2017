#include <vector>
#include <string>
#include <iostream>

using namespace std;
int row, col;
const int rs[4] = {0, 0, 1, -1};
const int cs[4] = {1, -1, 0, 0};

class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    row = rooms.size();
    if (row == 0) return;
    col = rooms.at(0).size();

    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
      if (rooms[i][j] == 0) dfs(i, j, 0, rooms);
    }
  }

  void dfs(int x, int y, int v, vector<vector<int> >& rooms) {
    if (x < 0 || x >= row || y < 0 || y >= col) return;
    rooms[x][y] = v;
    for (int z=0; z<4; ++z) {
      int nx = rs[z] + x, ny = y + cs[z];
      if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
      if (rooms[nx][ny] == -1 || rooms[nx][ny] <= v+1) continue;
      dfs(nx, ny, v+1, rooms);
    }
  }
};
