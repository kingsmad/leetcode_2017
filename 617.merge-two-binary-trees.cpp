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
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return nullptr;
    TreeNode* o = new TreeNode(0);
    if (t1) o->val += t1->val;
    if (t2) o->val += t2->val;
    o->left = mergeTrees(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
    o->right = mergeTrees(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);
    return o;
  }
};
