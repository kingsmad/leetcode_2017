// 1. consider single bit solutions + double bits solutions
class Solution {
  using ll = long long;
  const int mod = 1e9 + 7;
public:
    int numDecodings(string s) {
      if (s.size() == 0 || s.at(0) == '0') return 0;
      int n = s.size();
      vector<ll> dp(n+1, 0);
      dp[0] = 1;
      if (s[0] == '*') dp[1] = 9;
      else if (s[0] == '0') dp[1] = 0;
      else dp[1] = 1;

      for (int i=2; i<n+1; ++i) {
        char pre = s[i-2], c = s[i-1];
        // single bit
        if (c == '*') dp[i] = (dp[i] + 9 * dp[i-1] % mod) % mod;
        else if (c != '0') dp[i] = (dp[i] + dp[i-1]) % mod;

        // double bits
        if (pre == '1' || pre == '*') {
          if (c == '*') dp[i] = (dp[i] + 9 * dp[i-2] % mod) % mod;
          else dp[i] = (dp[i] + dp[i-2]) % mod;
        } 
        if (pre == '2' || pre == '*') {
          if (c == '*') dp[i] = (dp[i] + 6 * dp[i-2] % mod) % mod;
          else if (c < '7') dp[i] = (dp[i] + dp[i-2]) % mod;
        }
      }

      return dp[n];
    }
};
