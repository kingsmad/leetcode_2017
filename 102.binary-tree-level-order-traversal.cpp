#include <stack>
#include <vector>
#include <string>
#include <queue>

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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    queue<pair<TreeNode*, int> > ms;
    ms.push(make_pair(root, 0));

    while(!ms.empty()) {
      TreeNode* t = ms.front().first;
      int lv = ms.front().second;
      ms.pop();
      while(lv >= ans.size()) ans.push_back(vector<int>());

      ans[lv].push_back(t->val);
      if (t->left) ms.push(make_pair(t->left, lv+1));
      if (t->right) ms.push(make_pair(t->right, lv+1));
    }

    return ans;
  }
};
