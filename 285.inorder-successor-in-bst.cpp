#include <stack>
#include <iostream>
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
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    stack<pair<TreeNode*, bool> > ms;
    ms.push(make_pair(root, false));

    bool g_flag = false;
    while(!ms.empty()) {
      TreeNode* o = ms.top().first;
      bool done = ms.top().second;
      ms.pop();
      if (!done) {
        if (o->right) ms.push(make_pair(o->right, false));
        ms.push(make_pair(o, true));
        if (o->left) ms.push(make_pair(o->left, false));
      } else {
        if (g_flag) return o;
        if (o == p) g_flag = true;
      }
    }

    return nullptr;
  }
};
