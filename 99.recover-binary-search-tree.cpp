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
  void recoverTree(TreeNode* root) {
    pre = p_ = q_ = nullptr; 
    traverse(root); 
    swap(p_->val, q_->val);
  }

  void traverse(TreeNode* root) {
    if (!root) return;
    traverse(root->left);
    
    // For reverse pair (a, b), find first a and last b in all reverse pairs
    if (pre && pre->val > root->val) {
      if (!p_) p_ = pre;
      q_ = root;
    }

    pre = root;
    traverse(root->right);
  }
private:
  TreeNode* pre, *p_, *q_; 
};
