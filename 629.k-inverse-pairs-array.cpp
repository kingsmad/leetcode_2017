#include <cstring>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = 1100;
int n, k, dp[2][maxn];

class Solution {
 public:
  int kInversePairs(int n, int k) {
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    for (int i=2; i<=n; ++i) {
      ll sum = 0;
      deque<int> mq;
      for (int j=0; j<=k; ++j) {
        sum = (sum + dp[(i+1)%2][j]) % mod;
        mq.push_back(j);
        while(mq.size() && mq.front() + i - 1 < j) {
          sum = (sum + mod - dp[(i+1)%2][mq.front()]) % mod;
          mq.pop_front();
        }
        dp[i%2][j] = sum;
      }
    }

    return dp[n%2][k];
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  int n, k; scanf("%d%d", &n, &k); 
  Solution sol;
  int ans = sol.kInversePairs(n, k);
  printf("%d\n", ans);
  return 0;
}
#endif
