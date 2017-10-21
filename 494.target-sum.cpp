#include <vector>
using namespace std;

const int maxn = 30;
const int maxsum = 1e3 + 10;

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int n = nums.size();
    int ans = 0, pos = 0;
    dfs(0, 0, ans, nums, S);
    return ans;
  }

  void dfs(int pos, int sum, int& ans, vector<int>& nums, int target) {
    if (pos == nums.size()) {
      if (sum == target) ++ans;
      return;
    }
    
    dfs(pos+1, sum+nums.at(pos), ans, nums, target);
    dfs(pos+1, sum-nums.at(pos), ans, nums, target);
  }
};
