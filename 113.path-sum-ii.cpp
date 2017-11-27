#include <iostream>
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

vector<vector<int>> ans;
vector<int> path;
class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    ans.clear(); 
    path.clear();
    if (!root) return ans;

    path.push_back(root->val);
    dfs(root, root->val, sum); 
    return ans;
  }

  void dfs(TreeNode* root, int sum, int target) {
    if (!root->left && !root->right) {
      if (sum == target) ans.push_back(path);
      return;
    }

    if (root->left) {
      path.push_back(root->left->val);
      dfs(root->left, sum + root->left->val, target);
      path.pop_back();
    }

    if (root->right) {
      path.push_back(root->right->val);
      dfs(root->right, sum + root->right->val, target);
      path.pop_back();
    }
  }
};
