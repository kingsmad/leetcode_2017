#include <bits/stdc++.h>
using namespace std;
const int maxstate = pow(2, 21);

int dp[maxstate];
int n, gsum;

class Solution {
 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    n = maxChoosableInteger, gsum = desiredTotal;
    if (n * (n+1) / 2 < desiredTotal) return false;
    for (int i=0; i<(1<<(n+1)); ++i) dp[i] = -1;
    //memset(dp, -1, sizeof(dp));
    int state = 0;
    for (int i = 1; i <= n; ++i) state |= (1 << i);

    return calc(state);
  }

  bool calc(int state) {
    if (state == 0) return false;
    if (dp[state] != -1) return dp[state];

    int target = 0;
    for (int i = 1; i <= n; ++i)
      if (!(state & (1 << i))) target += i;
    target = gsum - target;

    // if one step can win
    for (int i = 1; i <= n; ++i)
      if ((state & (1 << i)) && i >= target) 
        return dp[state] = 1;

    // if after one step, the rival will fail
    for (int i = 1; i <= n; ++i)
      if (state & (1 << i)) {
        if (!calc(state ^ (1 << i))) 
          return dp[state] = 1;
      }

    return dp[state] = 0;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  Solution sol;
  int n, t;
  cin >> n >> t;
  bool ok = sol.canIWin(n, t);
  if (ok)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
#endif
