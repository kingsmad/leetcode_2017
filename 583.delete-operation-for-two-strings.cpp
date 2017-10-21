#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int maxn = 510;
int dp[maxn][maxn];

class Solution {
 public:

   int Calc(int x, int y, const string& w1, const string& w2) {
      if (x < 0 || y < 0) return 0;
      if (dp[x][y] != -1) return dp[x][y];  

      if (w1.at(x) == w2.at(y)) dp[x][y] = Calc(x-1, y-1, w1, w2) + 1;
      else dp[x][y] = max(Calc(x-1, y, w1, w2), Calc(x, y-1, w1, w2));
      return dp[x][y];
   }
   
  int minDistance(string word1, string word2) {
    memset(dp, -1, sizeof(dp));
    int n1 = word1.size(), n2 = word2.size();
    int ans = Calc(n1-1, n2-1, word1, word2);
    
    return n1 - ans + n2 - ans;
  }
};
