#include "bits/stdc++.h"
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
  int pathSum(TreeNode *root, int sum) {
    if (!root) return 0;
    return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
  }

  int dfs(TreeNode* o, int sum) {
    if (!o) return 0;
    int ans = 0;
    if (sum == o->val) ++ans;
    ans += dfs(root->left, sum - o->val);
    ans += dfs(root->right, sum - o->right);
    return ans;
  }
};
