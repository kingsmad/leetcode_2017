#include <vector>
#include <string>
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
  vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return vector<TreeNode*>();
    return dfs(1, n+1);      
  }

  vector<TreeNode*> dfs(int l, int r) {
    vector<TreeNode*> ans;
    if (l >= r) {
      ans.push_back(0);
      return ans;
    }
    
    for (int p=l; p<r; ++p) {
      vector<TreeNode*> lv = dfs(l, p);
      vector<TreeNode*> rv = dfs(p+1, r);
      for (TreeNode* lp : lv) for (TreeNode* rp : rv) {
        TreeNode* o = new TreeNode(p);
        o->left = lp;
        o->right = rp;
        ans.push_back(o);
      }
    }

    return ans;
  }
};
