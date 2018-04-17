#include <bits/stdc++.h>
using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    int ans = INT_MAX;
    dfs(root, 1, ans);
    return ans;
  }

  void dfs(TreeNode* o, int dep, int& ans) {
    if (!o) return;
    if (!o->left && !o->right) { ans = min(ans, dep); return;}

    dfs(o->left, dep + 1, ans);
    dfs(o->right, dep + 1, ans);
  }
};
