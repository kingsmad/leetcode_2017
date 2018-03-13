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
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<int> path;        
      vector<string> ans;
      dfs(root, path, ans);

      return ans;
    }

    string print(const vector<int>& vec) {
      int n = vec.size();
      string ans = "";
      for (int i=0; i<n; ++i) {
        ans += to_string(vec[i]);
        if (i+1 < n) ans += "->";
      }
      return ans;
    }

    void dfs(TreeNode* o, vector<int>& path, vector<string>& ans) {
      if (!o) return;

      // visit
      path.push_back(o->val);
      if (!o->left && !o->right) {
        ans.push_back(print(path)); 
      }

      dfs(o->left, path, ans);
      dfs(o->right, path, ans);
      path.pop_back();
    }
};
