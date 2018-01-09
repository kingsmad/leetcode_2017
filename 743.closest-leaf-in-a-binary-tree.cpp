#include <climits>
#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
 public:
  int findClosestLeaf(TreeNode* root, int k) {
    vector<pair<int, int> > leaves;
    dfs(root, 0, leaves);
    int diff = INT_MAX;
    int ans = leaves.front().second;
    for (auto& p : leaves) {
      int v = abs(p.first - k);
      if (v < diff) {
        ans = p.second;
        diff = v;
      }
    }
    return ans;
  }

  void dfs(TreeNode* o, int lv, vector<pair<int, int>>& leaves) {
    if (!o) return;
    if (!o->left && !o->right) { leaves.emplace_back(lv, o->val); return;}
    dfs(o->left, lv+1, leaves);
    dfs(o->right, lv+1, leaves);
  }
};
