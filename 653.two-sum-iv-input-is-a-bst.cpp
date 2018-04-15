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
  bool findTarget(TreeNode* root, int k) {
    vector<int> nums;
    dfs(root, nums);

    
    int n = nums.size();
    int p = 0, q = n - 1;
    while(p < q) {
      int v = nums[p] + nums[q];
      if ( v == k) return true;
      else if (v < k) ++p;
      else --q;
    }
    return false;
  }

  void dfs(TreeNode* o, vector<int>& nums) {
    if (!o) return;
    dfs(o->left, nums);
    nums.push_back(o->val);
    dfs(o->right, nums);
  }

};
