#include <map>
#include <iostream>
#include <vector>

using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

map<int, vector<TreeNode*>> smp;


class Solution {
 public:
  vector<vector<int>> findLeaves(TreeNode *root) {
    smp.clear();
    dfs(root);
    vector<vector<int>> ans;
    for (auto& p : smp) {
      vector<int> tmp;
      for (const TreeNode* o : p.second) tmp.push_back(o->val);
      ans.push_back(tmp);
    }

    return ans;
  }

  int dfs(TreeNode* root) {
    if (!root) return 0;
    int v = max(dfs(root->left), dfs(root->right)) + 1;
    smp[v].push_back(root);
    return v;
  }
};
