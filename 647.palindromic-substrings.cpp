#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int maxn = 1e3 + 10;
class Solution {
  int dp[maxn][maxn];
 public:
  int calc(const string& s, int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (s[l] != s[r]) return dp[l][r] = 0;
    if (l == r) return dp[l][r] = 1;
    if (l+1 == r) return dp[l][r] = (s[l] == s[r]) ? 1 : 0;
    return dp[l][r] = calc(s, l+1, r-1);
  }

  int countSubstrings(string s) { 
    int n = s.size();
    memset(dp, -1, sizeof(dp));
    int cnt = 0;
    for (int i=0; i<n; ++i) for (int j=i; j<n; ++j) {
      cnt += calc(s, i, j); 
    }

    return cnt;
  }
};
