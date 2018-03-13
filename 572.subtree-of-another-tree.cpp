#include <bits/stdc++.h>
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
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!t && !s) return true;
    if (!t || !s) return false;

    if (s->val == t->val)
      return isSubtree(s->left, t) || isSubtree(s->right, t) || (eq(s->left, t->left) && eq(s->right, t->right));
    else
      return isSubtree(s->left, t) || isSubtree(s->right, t);
  }

  bool eq(TreeNode* s, TreeNode* t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s->val != t->val) return false;
    return eq(s->left, t->left) && eq(s->right, t->right);
  }
};
