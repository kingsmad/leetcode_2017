#include <bits/stdc++.h>
// copy from https://blog.csdn.net/u011026968/article/details/81052040

using namespace std;
using ll = long long;

class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &ss) {
    if (startFuel >= target) return 0;
    int n = ss.size();
    if (n == 0) return startFuel >= target ? 0 : -1;
    ll dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = startFuel;
    
    int ans = INT_MAX;
    for (int i=0; i<n; ++i) {
      for (int j=i+1; j>=1; --j) {
        if (dp[j-1] < ss[i][0]) continue;
        dp[j] = max(dp[j-1] + ss[i][1], dp[j]);
        if (dp[j] >= target) ans = min(j, ans);
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
