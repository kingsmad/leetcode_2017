#include <bits/stdc++.h>
using namespace std;
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
    int diameterOfBinaryTree(TreeNode* root) {
      int ans = 0;
      dfs(root, ans);  
      return ans;
    }

    int dfs(TreeNode* o, int& ans){
      if (!o) return 0;
      int lv = dfs(o->left, ans);
      int rv = dfs(o->right, ans);
      ans = max(ans, lv + rv);
      return max(lv, rv) + 1;
    }
};
