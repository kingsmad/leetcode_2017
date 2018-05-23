#include <bits/stdc++.h>
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
  int findTilt(TreeNode* root) {
    int sum = 0, ans = 0;  
    dfs(root, sum, ans);
    return ans;
  }

  void dfs(TreeNode* o, int& sum, int& ans) {
    if (!o) {
      sum = 0;
      return ;
    }
    int lsum = 0, rsum = 0;
    dfs(o->left, lsum, ans);
    dfs(o->right, rsum, ans);
    ans += abs(lsum - rsum);
    sum = lsum + rsum + o->val;
  }
};
