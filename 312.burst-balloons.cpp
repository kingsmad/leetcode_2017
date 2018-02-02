#include <cstring>
#include <string>
#include <vector>


// line 22, if you want left and right sub-interval CAN BE EMPTY, then let z
// start from i, otherwise start from i+1
using namespace std;
const int maxn = 1e3 + 10;
int dp[maxn][maxn];

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    memset(dp, 0, sizeof(dp));
    int n = nums.size();

    for (int es = 1; es <= n; ++es) {
      for (int i = 0; i + es <= n; ++i) {
        int l = (i > 0) ? nums[i - 1] : 1;
        int r = (i + es < n) ? nums[i + es] : 1;
        for (int z = i; z < i + es; ++z) {
          dp[i][i + es] = max(
              dp[i][i + es], dp[i][z] + dp[z+1][i + es] + l * r * nums.at(z));
        }
      }
    }

    return dp[0][n];
  }

};
