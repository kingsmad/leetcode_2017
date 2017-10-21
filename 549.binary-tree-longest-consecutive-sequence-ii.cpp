#include <iostream>
#include <map>
#include <string>
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
 public:
  void dfs1(TreeNode* root, map<TreeNode*, int>& res, int direct) {
    if (!root) return;
    dfs1(root->left, res, direct);
    dfs1(root->right, res, direct);

    int ans = 1;
    if (root->left && root->val == root->left->val + direct) {
      ans = max(ans, res.at(root->left) + 1); 
    }

    if (root->right && root->val == root->right->val + direct) {
      ans = max(ans, res.at(root->right) + 1);
    }

    res[root] = ans;
    return;
  }

  void dfs(TreeNode* root, int& ans, const map<TreeNode*, int>& down_smp, 
           const map<TreeNode*, int>& up_smp) {
    if (!root) return;
    ans = max(ans, down_smp.at(root) + up_smp.at(root) - 1);
    dfs(root->left, ans, down_smp, up_smp);
    dfs(root->right, ans, down_smp, up_smp);
    return;
  }

  int longestConsecutive(TreeNode* root) {
    map<TreeNode*, int> down_smp;
    map<TreeNode*, int> up_smp;

    dfs1(root, down_smp, 1);
    dfs1(root, up_smp, -1);

    int ans = 0;
    dfs(root, ans, down_smp, up_smp);
    return ans;
  }
};
