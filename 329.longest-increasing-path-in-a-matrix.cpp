#include <bits/stdc++.h>
using namespace std;
const int rs[4] = {0, 0, -1, 1};
const int cs[4] = {1, -1, 0, 0};
int row, col;
vector<vector<int>> dp;
class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    row = matrix.size(); 
    if (row == 0) return 0;
    col = matrix[0].size();

    dp = vector<vector<int>>(row+1, vector<int>(col+1, -1));

    int ans = 0;
    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) 
      ans = max(ans, calc(i, j, matrix));

    return ans;
  }

  int calc(int x, int y, const vector<vector<int>>& matrix) {
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 1;
    for (int z=0; z<4; ++z) {
      int nx = x + rs[z], ny = y + cs[z];
      if (IsValid(nx, ny) && matrix[nx][ny] > matrix[x][y]) {
        dp[x][y] = max(dp[x][y], calc(nx, ny, matrix) + 1);
      }
    }
    return dp[x][y];
  }

  bool IsValid(int x, int y) {
    return (x >= 0 && x < row && y >=0 && y < col);
  }
};
