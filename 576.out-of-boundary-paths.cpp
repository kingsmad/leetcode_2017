#include <cstring>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

using ll = long long;

const int maxn = 60;
const ll mod = 1e9 + 7;

ll dp[maxn][maxn][maxn];

class Solution {
 public:
  ll Calc(int x, int y, int k, const int m, const int n) {
    if (x < 0 || x >= m || y < 0 || y >= n) return 1;
    if (dp[x][y][k] != -1) return dp[x][y][k];
    if (k == 0) return dp[x][y][k] = 0;

    ll ans = 0;
    ans = (ans + Calc(x-1, y, k-1, m, n)) % mod;
    ans = (ans + Calc(x+1, y, k-1, m, n)) % mod;
    ans = (ans + Calc(x, y-1, k-1, m, n)) % mod;
    ans = (ans + Calc(x, y+1, k-1, m, n)) % mod;
    return dp[x][y][k] = ans;
  }
  int findPaths(int m, int n, int N, int i, int j) {
    memset(dp, -1, sizeof(dp));
    return Calc(i, j, N, m, n);
  }
};
