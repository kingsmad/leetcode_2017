#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1e5 + 10;
int n, dp1[maxn], dp2[maxn];
int st[maxn][32], st1[maxn][32];

void InitRmq(const vector<int>& nums) {
  int n = nums.size();
  for (int i = 0; i < n; ++i) { st[i][0] = st1[i][0] = nums.at(i); }
  for (int j = 1; (1 << j) <= n; ++j) {
    for (int i = 0; i + (1 << j) <= n; ++i) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      st1[i][j] = min(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]);
    }
  }
}

int queryMax(int l, int r) {
  int k = 0;
  while (l + (1 << (k + 1)) <= r) ++k;
  return max(st[l][k], st[r - (1 << k)][k]);
}

int queryMin(int l, int r) {
  int k = 0;
  while (l + (1 << (k + 1)) <= r) ++k;
  return min(st1[l][k], st1[r - (1 << k)][k]);
}

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    n = prices.size();
    InitRmq(prices);
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    for (int i=1; i<n; ++i) {
      dp1[i] = max(dp1[i-1], prices.at(i) - queryMin(0, i+1));
    }
    for (int i=n-2; i>=0; --i) {
      dp2[i] = max(dp2[i+1], queryMax(i, n) - prices.at(i));
    }

    int ans = 0;
    for (int k=0; k<n; ++k) {
      ans = max(ans, dp1[k] + dp2[k]);
    }

    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  int n; scanf("%d", &n); 
  vector<int> prices(n, 0);
  for (int i=0; i<n; ++i) scanf("%d", &prices[i]);
  Solution sol;
  int ans = sol.maxProfit(prices);
  printf("%d\n", ans);
  return 0;
}
#endif
