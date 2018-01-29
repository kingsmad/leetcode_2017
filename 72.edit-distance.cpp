#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int maxn = 1e3 + 10;
int dp[maxn][maxn];

class Solution {
 public:
  int minDistance(string word1, string word2) {
    memset(dp, -1, sizeof(dp));
    return calc(word1.size(), word2.size(), word1, word2);
  }

  int calc(int x, int y, const string& s1, const string& s2) {
    if (x == 0) return y;
    if (y == 0) return x;
    if (dp[x][y] != -1) return dp[x][y];
    int n = s1.size(), m = s2.size();

    if (s1.at(x-1) == s2.at(y-1)) return dp[x][y] = calc(x-1, y-1, s1, s2);

    int ans = calc(x-1, y-1, s1, s2) + 1;
    ans = min(ans, calc(x-1, y, s1, s2) + 1);
    ans = min(ans, calc(x, y-1, s1, s2) + 1);


    return dp[x][y] = ans;
  }
};
