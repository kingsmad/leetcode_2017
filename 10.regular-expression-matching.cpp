#include <assert.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int maxn = 1e3 + 10;
int dp[maxn][maxn], f[maxn];

class Solution {
 public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    memset(dp, -1, sizeof(dp));
    return calc(n, m, s, p);
  }

  int calc(int x, int y, const string& s, const string& p) {
    if (x == 0 && y == 0) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    if (x > 0 && y > 0 && (p.at(y-1) == '.' || p.at(y-1) == s.at(x-1))) 
      return dp[x][y] = calc(x-1, y-1, s, p);

    if (y > 0 && p.at(y-1) == '*') {
      if (p.at(y-2) == '.') {
        for (int z=x; z>=0; --z) if (calc(z, y-2, s, p)) 
          return dp[x][y] = 1;
        return dp[x][y] = 0;
      } else {
        char c = p.at(y-2);
        int l = x; while(l>0 && s.at(l-1) == c) --l;
        for (int z=x; z>=l; --z) if (calc(z, y-2, s, p)) return dp[x][y] = 1;
        return dp[x][y] = 0;
      }
    }

    return dp[x][y] = 0;
  }
  
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  
}
#endif
