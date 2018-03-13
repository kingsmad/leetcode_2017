#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e3 + 10;
const int mod = 1e9 + 7;
ll dp[maxn][4];
int n, m;

class Solution {
 public:
  int numTilings(int N) {
    n = 2, m = N;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i=0; i<m; ++i) {
      for (int j=0; j<(1<<n); ++j) {
        if (dp[i][j]) dfs(i, 0, j, 0);
      }
    }

    return dp[m][0];
  }

  void dfs(int i, int j, int state, int nstate) {
    if (j == n) {
      dp[i+1][nstate] = (dp[i+1][nstate] + dp[i][state]) % mod;
      return;
    }
    // state already has row j, skip it
    if (bit(state, j)) { dfs(i, j+1, state, nstate); return;}

    // can have 1x2
    if (!bit(nstate, j)) {
      dfs(i, j+1, state, nstate | (1<<j));
      if (!bit(nstate, j)) {
        if (j>0 && !bit(nstate, j-1)) dfs(i, j+1, state, nstate | (1<<j) | (1<<(j-1)));
        if (j+1<n && !bit(nstate, j+1)) dfs(i, j+1, state, nstate | (1<<j) | (1<<(j+1)));
      }
    }

    // can have 2x1, 2x1xup, 2x1xdown
    if (j+1<n && !bit(state, j+1)) {
      dfs(i, j+2, state, nstate);
      if (!bit(nstate, j)) dfs(i, j+2, state, nstate | (1<<j));
      if (!bit(nstate, j+1)) dfs(i, j+2, state, nstate | (1<<(j+1)));
    }
  }

  inline bool bit(int x, int idx) {
    return x & (1<<idx);
  }
  
};
