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
  int sumNumbers(TreeNode* root) {
    vector<int> path;
    int ans = 0;
    dfs(root, &path, &ans);

    return ans;
  }

  void dfs(TreeNode* root, vector<int>* path, int* ans) {
    if (!root) return;
    path->push_back(root->val); 

    if (!root->left && !root->right) {
      *ans += Parse(*path);
      path->pop_back();
      return;
    }

    if (root->left) {
      dfs(root->left, path, ans);
    }

    if (root->right) {
      dfs(root->right, path, ans);
    }
    
    path->pop_back();
  }

  int Parse(const vector<int>& path) {
    int ans = 0;
    for (int d : path) {
      ans = 10 * ans + d;
    }
    return ans;
  }
};
