#include <climits>
#include <cstring>
#include <vector>
#include <string>

using namespace std;
using ll = long long;
const int maxn = 1e3 + 10;
const ll inf = 2ll * INT_MAX;
const int maxm = 60;
int n;
ll dp[maxn][maxm], sumv[maxn];

class Solution {
 public:
  int splitArray(vector<int>& nums, int m) {
    n = nums.size();
    memset(dp, -1, sizeof(dp));
    memset(sumv, 0, sizeof(sumv));
    sumv[0] = 0;
    for (int i=0; i<n; ++i) sumv[i+1] = sumv[i] + nums[i];

    return calc(n, m);
  }

  ll calc(int x, int y) {
    if (x < y) return -1;
    if (y == 1) return sum(0, x);

    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = inf;
    for (int z=1; z<x; ++z) {
      ll v = calc(z, y-1);
      if (v == -1) continue;
      dp[x][y] = min(max(sum(z, x), v), dp[x][y]);
    }
    return dp[x][y];
  }

  ll sum(int l, int r) {
    return sumv[r] - sumv[l];
  }
};
