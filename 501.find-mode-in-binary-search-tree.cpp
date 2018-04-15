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
  vector<int> findMode(TreeNode* root) {
    vector<int> nums;
    dfs(root, nums);
    int n = nums.size();

    int mode = -1;
    for (int i=0; i<n; ++i) {
      int q = i + 1; 
      while(q < n && nums.at(q) == nums.at(i)) ++q;
      mode = max(mode, q - i);
    }

    vector<int> ans;
    for (int i=0; i<n; ++i) {
      int q = i + 1;
      while(q < n && nums.at(q) == nums.at(i)) ++q;
      if (q - i == mode) ans.push_back(nums.at(i));
    }

    return ans;
  }

  void dfs(TreeNode* o, vector<int>& nums) {
    if (!o) return;
    dfs(o->left, nums);
    nums.push_back(o->val);
    dfs(o->right, nums);
  }
};
