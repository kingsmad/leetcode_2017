#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n, sum, k;


class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int pk) {
    n = nums.size();
    k = pk;
    sum = 0;
    for (int d : nums) sum += d;
    if (sum %k != 0) return false;
    sort(nums.begin(), nums.end());
     
    vector<int> pool(k, 0);
    return dfs(0, pool, nums);
  }

  bool dfs(int pos, vector<int>& pool, const vector<int>& nums) {
    if (pos == n) return true;
    int cnt = 0;
    for (int i=0; i<k; ++i) {
      if (pool.at(i) + nums.at(pos) > sum/k) return false;
      pool[i] += nums.at(pos);
      if (dfs(pos+1, pool, nums)) return true;
      pool[i] -= nums.at(pos);
    }
    
    return false;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  int n, k; scanf("%d%d", &n, &k);
  vector<int> nums(n, -1);
  for (int i=0; i<n; ++i) { scanf("%d", &nums[i]);}
  Solution sol;

  int ans = sol.canPartitionKSubsets(nums, k);
  return 0 * printf("%d\n", ans);
}
#endif
