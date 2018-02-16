#include <bits/stdc++.h>

using namespace std;
const int rs[4] = {0, 0, -1, 1};
const int cs[4] = {1, -1, 0, 0};
int row, col;

class Solution {
 public:
  vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    row = matrix.size();
    if (row == 0) return vector<pair<int, int>>();
    col = matrix.at(0).size();

    vector<vector<bool>> a1(row, vector<bool>(col, false));
    vector<vector<bool>> a2 = a1;

    for (int j = 0; j < col; ++j) dfs(0, j, a1, matrix);
    for (int i = 0; i < row; ++i) dfs(i, 0, a1, matrix);
    for (int j = 0; j < col; ++j) dfs(row - 1, j, a2, matrix);
    for (int i = 0; i < row; ++i) dfs(i, col - 1, a2, matrix);

    vector<pair<int, int>> ans;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (a1[i][j] && a2[i][j]) { ans.push_back({i, j}); }
      }
    }

    return ans;
  }

  void dfs(int x, int y, vector<vector<bool>>& a,
           const vector<vector<int>>& matrix) {
    a[x][y] = true;
    for (int z = 0; z < 4; ++z) {
      int nx = x + rs[z], ny = y + cs[z];
      if (nx >= 0 && nx < row && ny >= 0 && ny < col && !a[nx][ny]
          && matrix[nx][ny] >= matrix[x][y]) {
        dfs(nx, ny, a, matrix);
      }
    }
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {

}
#endif
