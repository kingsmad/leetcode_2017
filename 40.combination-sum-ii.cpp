#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  vector<vector<int> > ans;
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    ans.clear();
    sort(candidates.begin(), candidates.end());
    vector<int> path;
    dfs(0, path, target, candidates);

    return ans;
  }

  void dfs(int p, vector<int>& path, int target, const vector<int>& candidates) {
    int n = candidates.size();
    if (target == 0) { ans.push_back(path); return;}
    if (p == n) return;

    int v = candidates.at(p);

    // count duplicates 
    int ed = p + 1;
    while(ed < n && candidates.at(ed) == v) ++ed;
    int cnt = ed - p;

    int vcnt = 0;
    for (int i=0; i<=cnt && i*v<=target; ++i) {
      dfs(ed, path, target-i*v, candidates);
      path.push_back(v);
      ++vcnt;
    }
    while(vcnt--) path.pop_back();
  }
};
