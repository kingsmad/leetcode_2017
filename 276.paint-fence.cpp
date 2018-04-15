#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
 public:
  int numWays(int n, int k) {
    vector<int> dp(n+1, 0);
    if (n == 0 || k == 0) return 0;
    if (n == 1) return k;

    dp[0] = k;
    dp[1] = k * k;

    for (int i=2; i<n; ++i) {
      dp[i] = dp[i-1] * (k-1) + dp[i-2] * (k-1);
    }

    return dp[n-1];
  }
};
