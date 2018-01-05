#include <map>
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

map<TreeNode*, int> mcnt;

class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    mcnt.clear();
    build(root);

    return find(root, k);
  }

  int build(TreeNode* root) {
    if (!root) return 0;
    int v = build(root->left) + build(root->right);
    mcnt[root] = v + 1;
    return v + 1;
  }

  int find(TreeNode* root, int k) {
    int v1 = 0, v2 = 0;
    if (root->left) v1 = mcnt[root->left];
    if (root->right) v2 = mcnt[root->right];
    if (k == v1 + 1) return root->val;
    if (k < v1 + 1) return find(root->left, k);
    return find(root->right, k - v1 - 1);
  }
};
