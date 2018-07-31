#include <bits/stdc++.h>
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
  int findSecondMinimumValue(TreeNode* root) {
    set<int> ms;          
    dfs(root, ms);
    auto it = ms.begin();
    while(it != ms.end() && *it == *ms.begin()) ++it;
    if (it != ms.end()) return *it;
    return -1;
  }

  void dfs(TreeNode* o, set<int>& ms) {
    if (!o) return;
    ms.insert(o->val);
    dfs(o->left, ms);
    dfs(o->right, ms);
  }
};
