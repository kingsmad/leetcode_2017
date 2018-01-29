#include <vector>
#include <string>
#include <cstring>

using namespace std;
const int rs[2] = {-1, 0};
const int cs[2] = {0, -1};

const int maxn = 70;
int n, dp[maxn][maxn][maxn][maxn];
const int inf = 2e9 + 7;

class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    memset(dp, -1, sizeof(dp));
    n = grid.size();
    int ans = calc(n-1, n-1, n-1, n-1, grid);
    return max(ans, 0);
  }

  int calc(int x1, int y1, int x2, int y2, vector<vector<int>>& grid) {
    if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n
        || x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) return -inf;
    if (grid[x1][y1] == -1 || grid[x2][y2] == -1) return -inf;

    if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
    if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) {
      return dp[0][0][0][0] = grid[0][0];
    }
    
    // mark: initial ans as -inf, not 0
    int ans = -inf;
    for (int i=0; i<2; ++i) for (int j=0; j<2; ++j) {
      ans = max(ans, calc(x1+rs[i], y1+cs[i], x2+rs[j], y2+cs[j], grid));
    }
    if (ans < 0) return dp[x1][y1][x2][y2] = -inf;

    if (x1 == x2 && y1 == y2) {
      if (grid[x1][y1] == 1) ++ans;
    } else {
      if (grid[x1][y1] == 1) ++ans;
      if (grid[x2][y2] == 1) ++ans;
    }

    return dp[x1][y1][x2][y2] = ans;
  }
};
