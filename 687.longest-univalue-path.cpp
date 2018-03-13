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
  map<TreeNode*, int> ms;

 public:
  int longestUnivaluePath(TreeNode* root) {
    ms.clear();
    dfs(root);

    int ans = 0;
    dfs1(root, ans);

    return max(0, ans- 1);
  }

  int dfs(TreeNode* root) {
    if (!root) return 0;
    dfs(root->left);
    dfs(root->right);

    int ans = 1;
    if (root->left && root->left->val == root->val)
      ans = max(ans, ms[root->left] + 1);
    if (root->right && root->right->val == root->val)
      ans = max(ans, ms[root->right] + 1);
    return ms[root] = ans;
  }

  void dfs1(TreeNode* root, int& ans) {
    if (!root) return;
    dfs1(root->left, ans);
    dfs1(root->right, ans);

    int v = 1;
    if (root->left && root->left->val == root->val) v += ms[root->left];
    if (root->right && root->right->val == root->val) v += ms[root->right];

    ans = max(v, ans);
  }
};
