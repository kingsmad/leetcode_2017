#include <iostream>
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
  void dfs(TreeNode* root, int dep, const int d, const int v) {
    if (!root) return;  
    if (dep == d-1) nodes.push_back(root);
    /*if (dep < d-1 && !root-left && !root-right) {
      TreeNode* y = new TreeNode(v);
      TreeNode* x = new TreeNode(v);
      root->left = x;
      root->right = y;
    }*/
    dfs(root->left, dep+1, d);
    dfs(root->right, dep+1, d);
  }

  TreeNode* addOneRow(TreeNode* root, int v, int d) {
    nodes.clear();
    dfs(root, 1, d, v);
    for (TreeNode* o : nodes) {
      if (o->left) {
        TreeNode* u = new TreeNode(v);
        u->left = o->left;
        o->left = u;
      }
      if (o->right) {
        TreeNode* u = new TreeNode(v);
        u->right = o->right;
        o->right = u;
      }
    }

    return root;
  }
};
