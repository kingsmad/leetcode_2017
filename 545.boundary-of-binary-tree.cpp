#include <bits/stdc++.h>
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
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    vector<int> ans;
    if (root && (root->left || root->right)) ans.push_back(root->val);

    TreeNode* p = root->left;
    while(1) {
      if (!p || (!p->left && !p->right) ) break;
      ans.push_back(p->val);
      if (p->left) p = p->left;
      else p = p->right;
    }

    calc_leaves(root, ans);

    vector<int> tmp;  
    p = root->right;
    while(1) {
      if (!p || (!p->left && !p->right)) break;
      tmp.push_back(p->val);
      if (p->right) p = p->right;
      else p = p->left;
    }
    reverse(tmp.begin(), tmp.end());
    
    ans.insert(ans.end(), tmp.begin(), tmp.end());
    return ans;
  }

  void calc_leaves(TreeNode* o, vector<int>& ans) {
    if (!o) return;
    if (!o->left && !o->right) ans.push_back(o->val);
    calc_leaves(o->left, ans);
    calc_leaves(o->right, ans);
  }
};
