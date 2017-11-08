#include <algorithm>
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
  map<TreeNode*, int> smp;
 public:
  int longestConsecutive(TreeNode* root) {
    dfs(root);
    
    int ans = 0;
    for (auto& p : smp) ans = max(ans, p.second);
    return ans;
  }

  int dfs(TreeNode* root) {
    if (!root) return 0;
    int lv = dfs(root->left);
    int rv = dfs(root->right);

    int ans = 1;
    if (root->left && root->left->val == root->val + 1) 
      ans = max(ans, lv + 1);
    if (root->right && root->right->val == root->val + 1) 
      ans = max(ans, rv + 1);

    return smp[root] = ans;
  }
};
