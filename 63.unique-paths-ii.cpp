#include <cstring>
#include <vector>
#include <string>

using namespace std;

int row, col;
int dp[110][110];
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    row = obstacleGrid.size(), col = obstacleGrid.at(0).size();
    memset(dp, -1, sizeof(dp)); 
    dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
    
    return Calc(row-1, col-1, obstacleGrid);
  }

  int Calc(int x, int y, const vector<vector<int>>& grid) {
    if (x < 0 || x >= row || y < 0 || y >= col) return 0;
    if (grid[x][y] == 1) return 0;
    if (dp[x][y] != -1) return dp[x][y];

    return dp[x][y] = Calc(x-1, y, grid) + Calc(x, y-1, grid);
  }
};
