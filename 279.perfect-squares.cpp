#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 1e4 + 10;
const int maxk = 100;
int dp[maxk][maxn], s[maxk][maxn];
using ll = long long;

class Solution {
 public:
  int numSquares(int n) {
    memset(dp, -1, sizeof(dp)); 

    int i = 1;
    while((i+1) * (i+1) <= n ) ++i;
    return calc(i, n);
  }

  int calc(int x, int y) {
    if (y == 0) return 0;
    if (x == 1) return y;

    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = calc(x-1, y);
    for (int z=s[x-1][y]; z*x*x<=y; ++z) {
      int v = calc(x-1, y - z*x*x) + z;
      if (v <= dp[x][y]) {
        dp[x][y] = v;    
      }
    }

    return dp[x][y];
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  Solution sol; 
  int n; scanf("%d", &n);
  int ans = sol.numSquares(n);

  printf("%d\n", ans);
  return 0;
}
#endif
