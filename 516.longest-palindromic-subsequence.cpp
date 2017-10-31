#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn][maxn];

class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    memset(dp, -1, sizeof(dp));
    return Calc(0, s.size()-1, s);
  }

  int Calc(int p, int q, const string& s) {
    if (dp[p][q] != -1) return dp[p][q]; 
    if (p == q) return dp[p][q] = 1;
    if (p + 1 == q) return (s[p] == s[q]) ? 2 : 1;

    dp[p][q] = 0;
    if (s[p] == s[q]) dp[p][q] = Calc(p+1, q-1, s) + 2;
    dp[p][q] = max(Calc(p+1, q, s), dp[p][q]);
    dp[p][q] = max(Calc(p, q-1, s), dp[p][q]);

    return dp[p][q];
  }
};
