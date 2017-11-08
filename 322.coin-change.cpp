#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <climits>

using namespace std;
const int maxn = 1e5 + 10;
const int inf = INT_MAX - 10;

int dp[maxn];

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    memset(dp, -1, sizeof(dp)); 
    int ans = Calc(amount, coins);
    if (ans == inf) return -1;
    return ans;
  }

  int Calc(int sum, const vector<int>& coins) {
    if (dp[sum] != -1) return dp[sum];
    if (sum == 0) return dp[sum] = 0;

    int ans = inf;
    for (int d : coins) {
      if (d <= sum) ans = min(ans, Calc(sum-d, coins) + 1);
    }

    return dp[sum] = ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  int n; scanf("%d", &n);
  vector<int> coins;
  for (int i=0; i<n; ++i) { int d; scanf("%d", &d); coins.push_back(d);}
  int amount; scanf("%d", &amount);

  Solution sol;
  int ans = sol.coinChange(coins, amount);

  return 0 * printf("%d\n", ans);
}
#endif
