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
    return calc(root);         
  }
  
  TreeNode* calc(TreeNode* root) {
    if (!root) return nullptr;
    if (!root->left && !root->right) return root;

    TreeNode* t1 = calc(root->left);
    TreeNode* t2 = calc(root->right);

    if (t1) {
      t1->left = t2;
      t1->right = root;
      return t1;
    }
    if (t2) {
      t2->left = root;
    }
  }
};
