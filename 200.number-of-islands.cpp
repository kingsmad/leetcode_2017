#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int rs[4] = { 0, 0, 1, -1};
const int cs[4] = {1, -1, 0, 0};
const int maxn = 1e3 + 10;

int row, col, ans, c[maxn][maxn];

class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    ans = 0;
    row = grid.size();
    if (row == 0) return 0;
    col = grid.at(0).size();
    memset(c, 0, sizeof(c));
    
    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) if (grid[i][j] == '1' && !c[i][j]) {
      ++ans;
      dfs(i, j, grid);
    }

    return ans;
  }

  void dfs(int x, int y, const vector<vector<char>>& grid) {
    if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == '0' || c[x][y]) return;    
    c[x][y] = 1;
    for (int z=0; z<4; ++z) {
      dfs(x + rs[z], y + cs[z], grid);
    }
  }
};
