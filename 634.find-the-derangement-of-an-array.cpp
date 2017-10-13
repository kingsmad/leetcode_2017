#include <iostream>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 10;
const ll mod = 1e9 + 7;

class Solution {
  ll dp[3];
 public:
  int findDerangement(int n) {
    dp[0] = 0; dp[1] = 0; dp[2] = 1;
    for (int i=3; i<=n; ++i) {
      dp[i%3] = ((i-1) * (dp[(i-1)%3] + dp[(i-2)%3])) % mod;
    }
    return dp[n%3] % mod;
  }
};
