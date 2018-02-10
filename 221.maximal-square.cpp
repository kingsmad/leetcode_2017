#include <algorithm>
#include <string>
#include <vector>

using namespace std;
const int maxn = 1e3 + 10;
int row, col;
int lmax[maxn][maxn], umax[maxn][maxn];

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    row = matrix.size();
    if (row == 0) return 0;
    col = matrix.at(0).size();

    for (int j = 0; j < col; ++j) { umax[0][j] = matrix[0][j] - '0'; }
    for (int i = 0; i < row; ++i) { lmax[i][0] = matrix[i][0] - '0'; }

    for (int i = 1; i < row; ++i) {
      for (int j = 1; j < col; ++j) {
        if (matrix[i][j] == '0') {
          umax[i][j] = 0;
          lmax[i][j] = 0;
        } else {
          umax[i][j] = umax[i - 1][j] + 1;
          lmax[i][j] = lmax[i][j - 1] + 1;
        }
      }
    }

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    for (int i = 0; i < row; ++i) dp[i][0] = matrix[i][0] - '0';
    for (int j = 0; j < col; ++j) dp[0][j] = matrix[0][j] - '0';

    for (int i = 1; i < row; ++i)
      for (int j = 1; j < col; ++j) {
        if (matrix[i][j] == '0') {
          dp[i][j] = 0;
          continue;
        }
        dp[i][j] = dp[i - 1][j - 1];
        dp[i][j] = min(dp[i][j], lmax[i][j]-1);
        dp[i][j] = min(dp[i][j], umax[i][j]-1);
        ++dp[i][j];
      }

    int ans = 0;
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j) ans = max(ans, dp[i][j]);
    return ans * ans;
  }
};
#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  Solution sol; 
  vector<vector<char>> matrix = {{'0', '1'}};
  int ans = sol.maximalSquare(matrix);
  printf("%d\n", ans);
  return 0;
}
#endif
