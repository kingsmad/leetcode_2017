#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<int> > pal;
vector<int> dp;

class Solution {
 public:
  int minCut(string s) {
    int n = s.size();
    pal = vector<vector<int>>(n+1, vector<int>(n+1, false));

    for (int i=0; i<n; ++i) { pal[i][i] = pal[i][i+1] = true; }
    for (int es=2; es<=n; ++es) {
      for (int i=0; i+es<=n; ++i) {
        if (s[i] != s[i+es-1]) pal[i][i+es] = false;
        else pal[i][i+es] = pal[i+1][i+es-1];
      }
    }
    
    vector<int> dp(n+1);
    dp[0] = 0;
    for (int i=1; i<=n; ++i) {
      if (pal[0][i]) {dp[i] = 0; continue;}
      dp[i] = i - 1;
      for (int j=0; j<i; ++j) {
        if (pal[j][i]) dp[i] = min(dp[i], dp[j] + 1);
      }
    }

    return dp[n];
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  string str; cin >> str;
  Solution sol;
  int ans = sol.minCut(str);
  cout << ans << endl;
  return 0;
}
#endif

