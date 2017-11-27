#include <vector>
#include <string>
#include <climits>

using namespace std;

int row, col;
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    row = grid.size();
    if (row == 0) return 0;
    col = grid.at(0).size();

    vector<vector<int> > dp(row, vector<int>(col, -1));
    dp[0][0] = grid[0][0];
    int ans = Calc(row-1, col-1, dp, grid); 
    return ans;
  }

  int Calc(int x, int y, vector<vector<int>>& dp, const vector<vector<int>>& grid) {
    if (dp[x][y] != -1) return dp[x][y];
    int v = INT_MAX;
    if (x > 0) v = min(v, Calc(x-1, y, dp, grid));
    if (y > 0) v = min(v, Calc(x, y-1, dp, grid));
    return dp[x][y] = v + grid[x][y];
  }
};
