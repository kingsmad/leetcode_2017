#include <cstring>
#include <string>
#include <vector>

// when use memory lines repeatly, remember to set every element in that line 
// initialized.

using namespace std;
const int maxn = 1e5 + 10;
const int inf = 1e9 + 7;
int n, m, dp[maxn][2];

class Solution {
 public:
  int numDistinct(string s, string t) {
    n = s.size(), m = t.size();
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; ++i) dp[i][0] = 1;

    for (int j = 1; j <= m; ++j) {
      for (int i = 0; i <= n; ++i) {
        // vital line below
        if (i == 0) {
          dp[0][j % 2] = 0;
        } else {
          dp[i][j % 2] = dp[i - 1][j % 2];
          if (s[i - 1] == t[j - 1]) dp[i][j % 2] += dp[i - 1][(j - 1) % 2];
        }
      }
    }
    return dp[n][m % 2];
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  string s1 = "rabbbit", s2 = "rabbit";

  Solution sol;
  int ans = sol.numDistinct(s1, s2);

  printf("%d\n", ans);
  return 0;
}
#endif


// if remove line 24-26
/*
1 0 0 0 0 0 0 
1 1 0 0 0 0 0 
1 1 1 0 0 0 0 
1 1 1 1 0 0 0 
1 1 1 2 1 0 0 
1 1 1 3 3 0 0 
1 1 1 3 3 3 0 
1 1 1 3 3 3 3 


1 0 0 
1 1 0 
1 1 0 
1 1 0 
1 1 0 
1 1 0 
1 1 0 
1 1 0 
--------------------------------------------
1 0 0 
1 1 0 
2 1 0 
2 1 0 
2 1 0 
2 1 0 
2 1 0 
2 1 0 
--------------------------------------------
1 0 0 
1 0 0 
2 0 0 
2 2 0 
2 4 0 
2 6 0 
2 6 0 
2 6 0 
--------------------------------------------
1 0 0 
1 0 0 
1 0 0 
1 2 0 
3 4 0 
7 6 0 
7 6 0 
7 6 0 
--------------------------------------------
1 0 0 
1 0 0 
1 0 0 
1 0 0 
3 0 0 
7 0 0 
7 7 0 
7 7 0 
--------------------------------------------
1 0 0 
1 0 0 
1 0 0 
1 0 0 
1 0 0 
1 0 0 
1 7 0 
8 7 0 
--------------------------------------------
8*/
