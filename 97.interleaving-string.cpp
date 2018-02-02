#include <iostream>
#include <vector>

using namespace std;
const int maxn = 1e3 + 10;
int dp[maxn][maxn];

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int n = s1.size(), m = s2.size();
    if (n + m != s3.size()) return false;

    dp[0][0] = 1;
    for (int i=0; i<=n; ++i) for (int j=0; j<=m; ++j) {
      if (i>0 || j>0) dp[i][j] = 0 ;
      if (i > 0 && s1[i-1] == s3[i+j-1] && dp[i-1][j]) dp[i][j] = 1;
      if (j > 0 && s2[j-1] == s3[i+j-1] && dp[i][j-1]) dp[i][j] = 1;
    }

    return dp[n][m];
  }
};
