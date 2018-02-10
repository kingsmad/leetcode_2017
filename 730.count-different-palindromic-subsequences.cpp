#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

class Solution {
 public:
  int countPalindromicSubsequences(string S) {
    int n = S.size();
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));

    for (int i=0; i<n; ++i) dp[i][i+1] = 1;
    for (int es=2; es<=n; ++es) {
      for (int i=0; i+es<=n; ++i) {
        dp[i][i+es] = dp[i+1][i+es] + dp[i][i+es-1] - dp[i+1][i+es-1];
        if (S[i] == S[i+es-1]) dp[i][i+es] += 1 + dp[i+1][i+es-1];
      }
    }

    return dp[0][n];
  }
};
