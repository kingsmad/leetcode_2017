#include <stack>
#include <vector>
#include <string>
#include <iostream>

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
  vector<int> inorderTraversal(TreeNode* root) {
    stack<pair<TreeNode*, bool> > ms;
    vector<int> ans;
    if (!root) return ans;
    ms.push(make_pair(root, false));

    while(!ms.empty()) {
      TreeNode* tmp = ms.top().first;
      bool done = ms.top().second;
      ms.pop();
      if (!done) {
        if (tmp->right) ms.push(make_pair(tmp->right, false));
        ms.push(make_pair(tmp, true));
        if (tmp->left) ms.push(make_pair(tmp->left, false));
      } else {
        ans.push_back(tmp->val);
      }
    }

    return ans; 
  }
};
