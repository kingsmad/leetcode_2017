#include <vector>
#include <cstring>

using namespace std;
int n, k;

class Solution {
 public:
  int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
    n = flights.size(), k = days.at(0).size();
    vector<vector<int>> dp(2, vector<int>(n, -1));
    
    dp[0][0] = days[0][0];
    for (int j=1; j<n; ++j) if (flights[0][j]) dp[0][j] = days[j][0];

    for (int i=1; i<k; ++i) {
      for (int j=0; j<n; ++j) {
        dp[i%2][j] = -1;
        for (int z=0; z<n; ++z) {
          if (dp[(i+1)%2][z] != -1 && (flights[z][j] || z == j)) {
            dp[i%2][j] = max(dp[i%2][j], dp[(i+1)%2][z] + days[j][i]);
          }
        }
      }
    }

    int ans = 0;
    for (int j=0; j<n; ++j) ans = max(ans, dp[(k-1+2)%2][j]);
    return ans;
  }
};
