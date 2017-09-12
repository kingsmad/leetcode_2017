#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
      int dp[110][110];
      memset(dp, 0, sizeof(dp));

      int n = s.size();

      for (int st=1; st<=n; ++st) {
        for (int i=0; i+st<=n; ++i) {
          dp[i][i+st] = st;
          for (int k=i+1; k<i+st; ++k) {
            if (s[k-1] == s[i+st-1]) 
              dp[i][i+st] = min(dp[i][i+st], dp[i][k] + dp[k][i+st-1]);
            else 
              dp[i][i+st] = min(dp[i][i+st], dp[i][k] + dp[k][i+st]);
          }
        }
      }

      return dp[0][n];
    }
};

/*int main(int argc, char** argv) {

  string str; cin >> str;
  Solution sol;
  int ans = sol.strangePrinter(str);
  return 0 * printf("%d\n", ans);
}*/
