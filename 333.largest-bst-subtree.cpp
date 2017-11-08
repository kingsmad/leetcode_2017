#include <climits>
#include <map>
#include <stack>
#include <vector>

// binary search tree must be strictly 'less' or 'greater' in line 49/50
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
  int largestBSTSubtree(TreeNode *root) {
    int ans = 0, mx = INT_MIN, cnt = 0, mn = INT_MAX;
    dfs(root, &mx, &mn, &cnt, &ans);
    return ans;
  }

  bool dfs(TreeNode* root, int* mx, int* mn, int* cnt, int* ans) {
    if (!root) {
      *mx = INT_MIN;
      *mn = INT_MAX;
      *cnt = 0;
      return true;
    }

    int lmx, rmx, lmn, rmn, lcnt, rcnt;
    bool lvalid = dfs(root->left, &lmx, &lmn, &lcnt, ans);
    bool rvalid = dfs(root->right, &rmx, &rmn, &rcnt, ans);

    *mx = root->val;
    *mx = max(*mx, lmx);
    *mx = max(*mx, rmx);

    *mn = root->val;
    *mn = min(*mn, rmn);
    *mn = min(*mn, lmn);

    *cnt = lcnt + rcnt + 1;

    if (lvalid && rvalid) {
      if (root->left && lmx >= root->val) return false;
      if (root->right && rmn <= root->val) return false;
      *ans = max(*ans, *cnt);
      return true;
    }

    return false;
  }
};
