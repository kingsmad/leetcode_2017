// take care of dp[1], which needs no operations.
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
  const int maxn = 1e3 + 10;
public:
    int minSteps(int n) {
      int dp[maxn];
      for (int i=0; i<=n; ++i) {
        if (i == 1) dp[i] = 0;
        else dp[i] = i;
        for (int j=1; j<=i; ++j) {
          if (i%j == 0) {
            dp[i] = min(dp[i], dp[j] + 1 + (i/j - 1));
          }
        }
      }

      return dp[n];
    }

};
