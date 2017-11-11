#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int maxn = 1e3 + 10;

int dp[maxn][maxn];

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    memset(dp, -1, sizeof(dp));
    int n = prices.size();
    return Calc(0, n, prices);
  }

  int Calc(int x, int y, const vector<int>& prices) {
    if (y - x <= 1) return dp[x][y] = 0;
    if (dp[x][y] != -1) return dp[x][y];
    if (x + 2 == y) return dp[x][y] = max(0, prices.at(y-1) - prices.at(x));


    dp[x][y] = max(0, prices.at(y-1) - prices.at(x));
    for (int k=x+1; k<y; ++k) {
      dp[x][y] = max(dp[x][y], Calc(x, k, prices) + Calc(k+1, y, prices));
    }

    return dp[x][y];
  }
};
