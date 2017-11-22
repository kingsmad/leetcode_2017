#include <cstring>
#include <iostream>
#include <string>

using namespace std;
const int maxn = 1e3 + 10;
bool dp[maxn][maxn];

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    memset(dp, 0, sizeof(dp));

    for (int step=0; step<=n; ++step) {
      for (int i=0; i+step<=n; ++i) {
        if (step == 0 || step == 1) dp[i][i+step] = true;
        else if (s.at(i) == s.at(i+step-1) && dp[i+1][i+step-1]) {
          dp[i][i+step] = true;
        }
      }
    }

    int ans = 0, p = 0, q = 0;
    for (int i=0; i<n; ++i) for (int j=0; j<=n; ++j) if (dp[i][j]) {
      if (ans < j - i) {
        p = i, q = j;
        ans = j - i;
      }
    }

    return s.substr(p, q - p);
  }
};
