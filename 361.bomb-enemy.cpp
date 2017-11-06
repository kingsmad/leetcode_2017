#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e3 + 10;

int row, col;
const int rs[4] = {0, 0, 1, -1};
const int cs[4] = {-1, 1, 0, 0};


class Solution {
 public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    row = grid.size(), col = grid.at(0).size();

    vector<vector<int> > sum[4];
    for (int i=0; i<4; ++i) sum[i] = vector<vector<int>>(row, vector<int>(col, -1));
    for (int i=0; i<4; ++i) for (int x=0; x<row; ++x) for (int y=0; y<col; ++y) {
      Calc(x, y, i, grid, sum[i]); 
    }

    int ans = 0;
    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
      if (grid[i][j] != '0') continue;
      int s = 0;
      for (int k=0; k<4; ++k) s += sum[k][i][j];
      ans = max(s - 3 * (grid[i][j] == 'E'), ans);
    }

    return ans;
  }

  int Calc(int x, int y, const int dir, const vector<vector<char> >& grid, 
           vector<vector<int> >& csum) {
    if (x < 0 || x >= row || y < 0 || y >= col) return 0; 
    if (csum[x][y] != -1) return csum[x][y];
    if (grid[x][y] == 'W') return csum[x][y] = 0;

    return csum[x][y] = Calc(x+rs[dir], y+cs[dir], dir, grid, csum)
      + (grid[x][y] == 'E');
  }
};
