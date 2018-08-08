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
    ans += dfs(o->left, sum - o->val);
    ans += dfs(o->right, sum - o->val);
    return ans;
  }
};
