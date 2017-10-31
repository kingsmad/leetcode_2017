#include <climits>
#include <iostream>
#include <vector>

// MARK: line 17, there is no need to guess if only 1 member is in the range
using namespace std;

class Solution {
 public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
    
    return Calc(1, n+1, dp);
  }

  int Calc(int st, int ed, vector<vector<int>>& dp) {
    if (st + 1 >= ed) return 0;
    if (dp[st][ed] != -1) return dp[st][ed];

    int ans = INT_MAX;
    for (int p=st; p<ed; ++p) {
      ans = min(ans, p + max(Calc(st, p, dp), Calc(p+1, ed, dp)));
    }
    return dp[st][ed] = ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  int n; scanf("%d", &n);
  
  Solution sol;
  int ans = sol.getMoneyAmount(n);
  
  return 0 * printf("%d\n", ans);
}
#endif
