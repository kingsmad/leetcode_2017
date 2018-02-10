#include <bits/stdc++.h>
using namespace std;
#ifdef ROACH_ONLINE_JUDGE
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
 public:
  vector<TreeNode*> splitBST(TreeNode* root, int V) {
    if (!root) return vector<TreeNode*>(2, nullptr); 

    TreeNode* l, *r;
    if (root->val > V) {
      vector<TreeNode*> t = splitBST(root->left, V); 
      l = t[0], r = t[1];
      root->left = r;
      return {l, root};
    } else {
      vector<TreeNode*> t = splitBST(root->right, V);
      l = t[0], r = t[1];
      root->right = l;
      return {root, r};
    }
  }

  TreeNode* connect(TreeNode* p, TreeNode* q) {
    if (!p) return q;
    if (!q) return p;
    TreeNode* pack = connect(p->right, q->left);
    p->right = q;
    q->left = pack;
    return p;
  }
};
