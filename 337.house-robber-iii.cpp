#include <iostream>
#include <set>
#include <vector>

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
  int rob(TreeNode *root) {
    return max(Calc1(root), Calc0(root));
  }

  int Calc1(TreeNode* root) {
    if (!root) return 0;
    return Calc0(root->left) + Calc0(root->right) + root->val;
  }

  int Calc0(TreeNode* root) {
    if (!root) return 0;
    return max(Calc1(root->left), Calc0(root->left)) \
              + max(Calc1(root->right), Calc0(root->right));
  }
 
};
