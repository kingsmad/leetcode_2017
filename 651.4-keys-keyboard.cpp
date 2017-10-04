#include <math.h>
#include <stdio.h>
#include <map>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 100;

class Solution {
public:
  int maxA(int N) {
    int dp[100];
    for (int i=0; i<=N; ++i) {
      dp[i] = i;
      for (int j=0; j<=i-3; ++j) {
        dp[i] = max(dp[i], dp[j] * (i-j-2+1));
      }
    }

    return dp[N];
  }
};

