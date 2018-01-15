#include <iostream>
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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;
    if (root->val > key) {
      root->left = deleteNode(root->left, key);
      return root;
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
      return root;
    }

    if (!root->left) return root->right;
    if (!root->right) return root->left;
    delete root;
    return connect(root->left, root->right);
  }

  TreeNode* connect(TreeNode* p, TreeNode* q) {
    if (!p) return q;
    if (!q) return p;
    TreeNode* pack = connect(p->right, q->left);
    q->left = pack;
    p->right = q;
    return p;
  }
};
