#include <vector>
using namespace std;

class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    for (int i=0; i<n; ++i) {
      for (int j=0; j<i; ++j) {
        if (nums.at(i) > nums.at(j)) dp[i] = max(dp[i], dp[j]+1);
      }
    }
    int ma = 0;
    for (int i=0; i<n; ++i) ma = max(ma, dp[i]);

    vector<vector<int> > dp1(n, vector<int>(ma+1, -1));
    int ans = 0;
    for (int i=0; i<n; ++i) ans += calc(i, ma, dp1, nums);
    return ans;
  }

  int calc(int pos, int k, vector<vector<int>>& dp, vector<int>& nums) {
    if (dp[pos][k] != -1) return dp[pos][k];
    if (k == 1) return dp[pos][k] = 1;
    if (k > pos+1) return dp[pos][k] = 0;
    dp[pos][k] = 0;
    for (int j=0; j<pos; ++j) {
      if (nums.at(pos) > nums.at(j)) dp[pos][k] += calc(j, k-1, dp, nums);  
    }
    return dp[pos][k];
  }
};
