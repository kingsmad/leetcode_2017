#include <cstring>
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;
ll dp[2][3][2];

class Solution {
 public:
  int checkRecord(int n) {
    memset(dp, 0, sizeof(dp));
    for (int i=0; i<2; ++i) for (int j=0; j<3; ++j) for (int z=0; z<2; ++z)
      dp[i][j][z] = 1;
    
    for (int i=1; i<=n; ++i) {
      for(int j=0; j<3; ++j) {
        for (int z=0; z<2; ++z) {
          dp[i%2][j][z] = dp[(i+1)%2][2][z];
          if (z > 0) dp[i%2][j][z] = (dp[i%2][j][z] + dp[(i+1)%2][2][z-1]) % mod;
          if (j > 0) dp[i%2][j][z] = (dp[i%2][j][z] + dp[(i+1)%2][j-1][z]) % mod;
        }
      }
    }

    return dp[n%2][2][1];
  }

};
