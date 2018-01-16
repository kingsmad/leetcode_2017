#include <math.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;
const int maxn = 1e5 + 10;
int dp[maxn];

class Solution {
 public:
  int numSquares(int n) {
    memset(dp, -1, sizeof(dp));
    return calc(n);
  }

  int calc(int x) {
    if (x == 0) return 0;
    if (dp[x] != -1) return dp[x];
    dp[x] = x;
    for (int i=1; i*i<=x; ++i) dp[x] = min(dp[x], calc(x-i*i) + 1);
    return dp[x];
  }
  
};
