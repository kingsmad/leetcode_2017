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
    if (!root) return nullptr;
    if (root->val == key) {

    }

    TreeNode* o = Find(root, key);
    if (!o) return root;
   
    TreeNode* u = (o->left && o->left->val == key) ? o->left : o->right;

    if (!u->left) {
      o->left = u->right;
      return root;
    }

    TreeNode* tmp = u->left;
    while(tmp->right) tmp = tmp->right;

    tmp->right = u->right;

    o->left = u->left;
    return root;
  }

  TreeNode* Find(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (root->left && root->left->val == key) return root;
    if (root->right && root->right->val == key) return root;

    int v = root->val;
    if (key < v) return Find(root->left, key);
    else return Find(root->right, key);
  }

};
