#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;
const int maxn = 2e3 + 10;
int8_t dp[maxn][maxn];

class Solution {
 public:
  bool isMatch(string s, string p) {
    // do not use memset(dp, -1, sizeof(dp)), will TLE
    for (int i=0; i<s.size()+1; ++i) for (int j=0; j<p.size()+1; ++j) dp[i][j] = -1;
    return calc(s.size(), p.size(), s, p);
  }

  bool calc(int x, int y, const string& s1, const string& s2) {
    if (dp[x][y] != -1) return dp[x][y];

    if (x == 0 && y == 0) return dp[x][y] = 1;
    if (y == 0) return dp[x][y] = 0;
    if (x == 0) {
      bool ok = 1;
      for (int i=0; i<y; ++i) if (s2.at(i) != '*') return dp[x][y] = 0;
      return dp[x][y] = 1;
    }


    if (s2.at(y-1) == '?' || s1.at(x-1) == s2.at(y-1)) return dp[x][y] = calc(x-1, y-1, s1, s2);
    if (s2.at(y-1) == '*') {
      for (int i=x; i>=0; --i) if (calc(i, y-1, s1, s2)) return dp[x][y] = 1;
    }
    return dp[x][y] = 0;
  }
  
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  string s1, s2; cin >> s1 >> s2;
  Solution sol;
  bool ans = sol.isMatch(s1, s2);
  if (ans) printf("TRUE\n");
  else printf("FALSE\n");
  return 0;
}
#endif
