#include <iostream>
#include <vector>

using namespace std;
const int maxn = 2e4 + 10;
const int maxm = 110;
const int inf = 2e9 + 7;
int n, m, dp[maxn][maxm];

class Solution {
 public:
  string minWindow(string S, string T) {
    n = S.size(), m = T.size();
    dp[0][0] = 0; 
    for (int i=0; i<=n; ++i) dp[i][0] = 0;
    for (int i=1; i<=m; ++i) dp[0][i] = inf; 

    for (int i=1; i<=n; ++i) {
      for (int j=1; j<=m; ++j) {
        if (S.at(i-1) == T.at(j-1)) dp[i][j] = 1 + dp[i-1][j-1];
        else dp[i][j] = dp[i-1][j] + 1;
      }
    }

    int mi = inf;
    for (int i=0; i<=n; ++i) mi = min(mi, dp[i][m]);
    if (mi == inf) return "";

    int p = 0;
    for (; p<=n; ++p) if (mi == dp[p][m]) break;
    return S.substr(p-mi, mi); 
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  string s, t; cin >> s >> t;
  Solution sol; 
  string ans = sol.minWindow(s, t);
  cout << ans << endl;
  return 0;
}
#endif
