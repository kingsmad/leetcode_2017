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
  map<TreeNode*, bool> ms;
 public:
  int countUnivalSubtrees(TreeNode* root) {
    ms.clear();
    dfs(root);
    return dfs1(root);
  }

  bool dfs(TreeNode* o) {
    if (!o) return true;
    if (ms.count(o) > 0) return ms.at(o);

    if (o->left && o->left->val != o->val) return ms[o] = false;
    if (o->right && o->right->val != o->val) return ms[o] = false;
    return ms[o] = (dfs(o->right) && dfs(o->left));
  }

  int dfs1(TreeNode* o) {
    if (!o) return 0;
    int ans = dfs1(o->left) + dfs1(o->right);
    if (dfs(o)) ++ans;
    return ans;
  }
};
