#include <stack>
#include <iostream>
#include <vector>
#include <map>
#include <set>

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
  void flatten(TreeNode* root) {
    if (!root) return;
    vector<TreeNode*> nodes;
    stack<TreeNode*> ms;
    ms.push(root);
    while(ms.size()) {
      TreeNode* o = ms.top();
      ms.pop();
      nodes.push_back(o);
      if (o->right) ms.push(o->right);
      if (o->left) ms.push(o->left);
    }

    for (int i=0; i+1<nodes.size(); ++i) {
      nodes[i]->left = 0;
      nodes[i]->right = nodes[i+1];
    }
    nodes.back()->right = 0;
  }
};
