#include <map>
#include <climits>
#include <vector>
#include <string>

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
  map<TreeNode*, int> mxp;
  map<TreeNode*, int> mnp;
 public:
  bool isValidBST(TreeNode* root) {
    mxp.clear();
    mnp.clear();

    return Calc(root);

  }

  bool Calc(TreeNode* root) {
    if (!root) return true;
    if (root->left && root->val <= Max(root->left)) return false;
    if (root->right && root->val >= Min(root->right)) return false;
    return Calc(root->left) && Calc(root->right);
  }

  int Min(TreeNode* root) {
    if (mnp.count(root)) return mnp.at(root);
    int v = root->val;
    if (root->left) v = min(Min(root->left), v); 
    if (root->right) v = min(Min(root->right), v);
    return mnp[root] = v;
  }

  int Max(TreeNode* root) {
    if (mxp.count(root)) return mxp.at(root);
    int v = root->val;
    if (root->left) v = max(v, Max(root->left));
    if (root->right) v = max(v, Max(root->right));
    return mxp[root] = v;
  }
};
