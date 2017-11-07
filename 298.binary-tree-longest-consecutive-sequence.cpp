#include <vector>
#include <string>
#include <algorithm>
#include <map>
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
  int longestConsecutive(TreeNode* root) {
    if (!root) return 0;
    int lv = longestConsecutive(root->left);
    int rv = longestConsecutive(root->right);

    int ans = 1;
    ans = max(ans, lv);
    ans = max(ans, rv);

    if (root->left && root->left->val == root->val + 1) 
      ans = max(ans, lv + 1);
    if (root->right && root->right->val == root->val + 1)
      ans = max(ans, rv + 1);

    return ans;
  }
};
