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

class Solution {
  map<TreeNode*, TreeNode*> node2fa;
  map<TreeNode*, int> node2lv;
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    node2fa.clear();
    node2lv.clear();
    dfs(root, 0, nullptr);

    int pv = node2lv[p], qv = node2lv[q];
    while(pv > qv) { p = node2fa[p]; --pv;}
    while(qv > pv) { q = node2fa[q]; --qv;}

    while(p != q) {
      p = node2fa[p];
      q = node2fa[q];
    }

    return q;
  }

  void dfs(TreeNode* root, int v, TreeNode* pa) {
    if (!root) return;

    node2lv.emplace(root, v); 
    node2fa.emplace(root, pa);

    if (root->left) dfs(root->left, v+1, root);
    if (root->right) dfs(root->right, v+1, root);
  }
};
