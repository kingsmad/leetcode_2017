/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  void dfs(TreeNode* root, map<TreeNode*, int>& n2v) {
    if (!root) return;
    dfs(root->left, n2v); 
    dfs(root->right, n2v);

    int ans = root->val;
    if (root->left) ans += n2v.at(root->left);
    if (root->right) ans += n2v.at(root->right);
    n2v.emplace(root, ans);
  }

    bool checkEqualTree(TreeNode* root) {
      if (!root) return false;
      map<TreeNode*, int> n2v; 
      dfs(root, n2v);

      int rv = n2v.at(root);
      if (rv % 2 != 0) return false; 
      
      stack<TreeNode*> mstack;
      mstack.push(root);
      while(!mstack.empty()) {
        TreeNode* t = mstack.top();
        mstack.pop();
        if (n2v.at(t) == rv/2 && t != root) return true;
        if (t->left) mstack.push(t->left);
        if (t->right) mstack.push(t->right);
      }

      return false;
    }
};
