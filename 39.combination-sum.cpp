#include <iostream>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int>> ans;
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    ans.clear();
    vector<int> path;
    dfs(0, path, target, candidates);
    return ans;
  }

  void dfs(int p, vector<int>& path, int target, const vector<int>& candidates) {
    int n = candidates.size();
    if (target == 0) { ans.push_back(path); return;}
    if (p == n) {
      return;
    }

    const int v = candidates.at(p);
    int cnt = 0;
    for (int i=0; i*v <= target; ++i) {
      dfs(p+1, path, target-i*v, candidates);
      path.push_back(v);
      ++cnt;
    }
    while(cnt--) path.pop_back();
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  int n, target; scanf("%d%d", &n, &target);
  vector<int> nums(n, 0);
  for (int i=0; i<n; ++i) scanf("%d", &nums[i]);
  Solution sol;
  vector<vector<int>> ans = sol.combinationSum(nums, target);
  for (const vector<int>& v : ans) {
    for (int d : v) printf("%d ", d); 
    printf("\n");
  }
  return 0;
}
#endif
