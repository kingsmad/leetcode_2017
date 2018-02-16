#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<int> dp;

 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int tot = accumulate(nums.begin(), nums.end(), 0);
    if (tot % k != 0) return false;

    int n = nums.size();
    sort(nums.begin(), nums.end());
    dp = vector<int>(1<<(n+1), -1);

    return dfs(0, nums, tot/k, k);
  }

  int dfs(int state, const vector<int>& nums, const int target, const int k) {
    if (dp[state] != -1) return dp[state];

    int sum = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (state & (1 << i)) sum += nums.at(i);
    }
   
    if (sum == k * target) return dp[state] = 1;

    sum = sum % target;
    for (int i = 0; i < n; ++i) {
      if (state & (1 << i)) continue;
      int v = sum + nums.at(i);
      if (v > target) return dp[state] = 0;
      if (v <= target && dfs(state | (1<<i), nums, target, k)) return dp[state] = 1;
    }

    return dp[state] = 0;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  freopen("in.txt", "r", stdin);
  Solution sol;
  int n, k;
  cin >> n >> k;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; ++i) scanf("%d", &nums[i]);

  bool ok = sol.canPartitionKSubsets(nums, k);
  if (ok)
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
#endif
