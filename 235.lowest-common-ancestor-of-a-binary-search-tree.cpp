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
  unordered_map<TreeNode*, TreeNode*> fa; 
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    dfs(root, 0);
    int dep1 = 0, dep2 = 0;
    for (TreeNode* o=p; o!=root; o=fa[o]) ++dep1;
    for (TreeNode* o=q; o!=root; o=fa[o]) ++dep2;
    while(dep1 > dep2) { p=fa[p]; --dep1;}
    while(dep2 > dep1) { q=fa[q]; --dep2;}

    while(p != q) {
      p = fa[p], q = fa[q];
    }
    return p;
  }

  void dfs(TreeNode* o, TreeNode* u) {
    if (!o) return;
    fa[o] = u;
    dfs(o->left, o);
    dfs(o->right, o);
  }
};
