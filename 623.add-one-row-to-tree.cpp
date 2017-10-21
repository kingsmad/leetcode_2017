#include <iostream>
#include <assert.h>
#include <map>
#include <unordered_map>
#include <vector>

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
  vector<TreeNode*> nodes;
 public:
  void dfs(TreeNode* root, int dep, const int d) {
    if (!root) return;  
    if (dep == d-1) nodes.push_back(root);
    dfs(root->left, dep+1, d);
    dfs(root->right, dep+1, d);
  }

  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    nodes.clear();
    if (d == 1) {
      TreeNode* u = new TreeNode(v);
      u->left = root;
      return u;
    }
    dfs(root, 1, d);
    //assert(nodes.size() > 0);
    for (TreeNode* o : nodes) {
    //  if (o->left) {
        TreeNode* u = new TreeNode(v);
        u->left = o->left;
        o->left = u;
     // }
      //if (o->right) {
        u = new TreeNode(v);
        u->right = o->right;
        o->right = u;
     // }
    }

    return root;
  }
};
