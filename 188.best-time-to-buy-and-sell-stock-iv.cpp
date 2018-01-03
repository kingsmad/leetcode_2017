// divide and conquer optimization
// dp[i][j]: in [0, j], use the j-th element as the right end, and i times tran-
// sactions, how much money can we make.
#include <climits>
#include <sys/times.h>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
const int maxn = 1e4 + 10;
int n;
int dp[2][maxn];

int st[maxn][32];
void InitRmq(const vector<int>& nums) {
  int n = nums.size();
  for (int i = 0; i < n; ++i) { st[i][0] = nums.at(i); }
  for (int j = 1; (1 << j) <= n; ++j) {
    for (int i = 0; i + (1 << j) <= n; ++i) {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
}

int queryMin(int l, int r) {
  int k = 0;
  while (l + (1 << (k + 1)) <= r) ++k;
  return min(st[l][k], st[r - (1 << k)][k]);
}

void calc(int i, int lj, int rj, int ls, int rs, const vector<int>& prices) {
  int md = (lj + rj) / 2;

  // search opt in [ls, mid]
  dp[i%2][md] = dp[(i+1)%2][ls] + prices[md] - queryMin(ls, md+1);
  int ops = ls;
  for (int t=ls; t<min(md, rs); ++t) {
    int v = dp[(i+1)%2][t] + prices[md] - queryMin(t, md+1);
    if (v > dp[i%2][md]) {
      dp[i%2][md] = v;
      ops = t;
    }
  }

  //printf("dp[%d][%d] has opt s at %d with value %d\n", i, md, ops, dp[i%2][md]);
  
  //printf("%d %d %d %d %d %d\n", i, lj, rj, ls, rs, ops);
  if (lj < md) calc(i, lj, md, ls, ops+1, prices);
  if (md+1 < rj) calc(i, md+1, rj, ops, rs, prices);
}

class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    clock_t stm = clock();
    int n = prices.size();
    if (n < 2) return 0;

    if (k > n/2) return CountInf(prices);

    // printf("current k is: %d\n", k);

    memset(dp, 0, sizeof(dp));
    InitRmq(prices);

    for (int i=1; i<=k; ++i) {
      calc(i, 0, n, 0, n, prices);
      printf("%d\n", i);
    }
  
    int ans = 0;
    for (int i=0; i<n; ++i) ans = max(dp[k%2][i], ans);
    
    printf("running time is %f\n", (float)((clock() - stm) / (10*CLOCKS_PER_SEC)));
    return ans;
  }

  int CountInf(vector<int>& prices) {
    int ans = 0; 
    int n = prices.size();
    for (int i=0; i+1<n; ++i) {
      int v = prices.at(i+1) - prices.at(i);
      if (v > 0) ans += v;
    }
    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> nums(n, 0);
  for (int i = 0; i < n; ++i) scanf("%d", &nums[i]);

  Solution sol;
  int ans = sol.maxProfit(k, nums);
  printf("%d\n", ans);
}
#endif
