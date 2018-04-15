#include <bits/stdc++.h>

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
  int sumOfLeftLeaves(TreeNode* root) {
    set<TreeNode*> ms;
    dfs1(root, ms);
    int ans = 0;
    dfs2(root, ans, ms);
    return ans;
  }

  void dfs1(TreeNode* o, set<TreeNode*>& ms) {
    if (!o) return;
    if (!o->left && !o->right) ms.insert(o);
    dfs1(o->left, ms);
    dfs1(o->right, ms);
  }

  void dfs2(TreeNode* o, int& tot, const set<TreeNode*>& ms) {
    if (!o) return;
    if (o->left && ms.count(o->left)) tot += o->left->val;
    dfs2(o->left, tot, ms);
    dfs2(o->right, tot, ms);
  }
};
