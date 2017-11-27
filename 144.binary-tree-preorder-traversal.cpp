#include <stack>
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
public:
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return vector<int>();
    stack<TreeNode*> ms;
    ms.push(root);
    vector<int> ans;
    while(ms.size()) {
      TreeNode* tmp = ms.top();
      ms.pop();
      ans.push_back(tmp->val);
      if (tmp->right) ms.push(tmp->right);
      if (tmp->left) ms.push(tmp->left);
    }

    return ans;
  }
};
