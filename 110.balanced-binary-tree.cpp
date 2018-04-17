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
  bool ok = false;
  unordered_map<TreeNode*, int> node2dep;
public:
  bool check(TreeNode* root) {
    if (!root) return true;
    int lv = dfs(root->left), rv = dfs(root->right);
    if (abs(lv - rv) > 1) return false;
    
    return isBalanced(root->left) && isBalanced(root->right);

  }

  bool isBalanced(TreeNode* root) {
    node2dep.clear();  
    return check(root);
  }

  int dfs(TreeNode* o) {
    if (!o) return 0;
    if (node2dep.count(o) > 0) return node2dep.at(o); 
    return max(dfs(o->left), dfs(o->right)) + 1;
  }
};
