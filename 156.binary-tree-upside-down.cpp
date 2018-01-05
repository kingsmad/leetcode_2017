#include <vector>
#include <string>
#include <iostream>

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
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    TreeNode* ans = nullptr;
    calc(root, &ans);
    return ans;
  }
  
  TreeNode* calc(TreeNode* root, TreeNode** newRoot) {
    if (!root) return root;
    if (!root->left && !root->right) {
      *newRoot = root;
      return root;
    }
    TreeNode* t1 = calc(root->left, newRoot);
    t1->left = root->right;
    t1->right = root;

    root->left = root->right = nullptr;
    return t1->right;
  }
};
