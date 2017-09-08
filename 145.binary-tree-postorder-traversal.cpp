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
    vector<int> postorderTraversal(TreeNode* root) {
      vector<int> ans;
      if (!root) return ans;
      stack<pair<TreeNode*, bool>> ms;           
      ms.push(make_pair(root, false));
      while(!ms.empty()) {
        TreeNode* t = ms.top().first;
        bool done = ms.top().second;
        ms.pop();
        if (!done) {
          ms.push(make_pair(t, true));
          if (t->right) ms.push(make_pair(t->right, false));
          if (t->left) ms.push(make_pair(t->left, false));
        } else {
          ans.push_back(t->val); 
        }
      }
      return ans;
    }
};
