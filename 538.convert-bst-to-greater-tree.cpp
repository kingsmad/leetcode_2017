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
  TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    dfs(root, sum);
    return root;
  }

  void dfs(TreeNode* o, int& prev) {
    if (!o) return;
    dfs(o->right, prev);
    int v = o->val;
    o->val += prev;
    prev += v;
    dfs(o->left, prev);
  }
};
