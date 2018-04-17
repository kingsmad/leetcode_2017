/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
  bool ok_ = false;
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    ok_ = false;
    dfs(root, 0, sum);
    return ok_;
  }

  void dfs(TreeNode* o, int path, int sum) {
    if (ok_) return;
    if (!o) return;
    path = o->val + path;
    if (path == sum && !o->left && !o->right) {
      ok_ = true;
      return;
    }
    dfs(o->left, path, sum);
    dfs(o->right, path, sum);
  }

};
