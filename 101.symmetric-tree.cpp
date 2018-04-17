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
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> q1, q2;
    q1.push(root->left);
    q2.push(root->right);

    while(1) {
      if (q1.empty() && q2.empty()) return true; 
      if (q1.empty() || q2.empty()) return false;
      TreeNode* l = q1.front(), *r = q2.front();
      q1.pop(), q2.pop();
      if (!l && !r) continue;
      if (!l || !r || l->val != r->val) return false;
      q1.push(l->left);
      q1.push(l->right);
      q2.push(r->right);
      q2.push(r->left);
    }

    return true;
  }
};
