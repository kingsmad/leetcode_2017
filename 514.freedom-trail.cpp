#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int inf = 1e9 + 10;
int n, m, dp[maxn][maxn];

class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    int n = ring.size(), m = key.size();
    memset(dp, -1, sizeof(dp));

    // dp[i][j] = min(dp[i-1][k] + dis(k, j) + 1)
    for (int j=0; j<n; ++j) dp[0][j] = min(j, n-j);

    for (int i=1; i<=m; ++i) {
      for (int j=0; j<n; ++j) {
        dp[i][j] = inf;
        if (key[i-1] != ring[j]) continue; 
        for (int k=0; k<n; ++k) {
          int v = abs(k - j);
          v = min(v, n-v);
          dp[i][j] = min(dp[i][j], dp[i-1][k] + v + 1);
        }
      }
    }
    
    int ans = inf;
    for (int j=0; j<n; ++j) ans = min(ans, dp[m][j]);
    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  /*freopen("in.txt", "r", stdin);
  string s1, s2; cin >> s1 >> s2; */
  string s1 = "godding", s2 = "gd";
  Solution sol;
  int ans = sol.findRotateSteps(s1, s2);
  printf("%d\n", ans);
  return 0;
}
#endif
