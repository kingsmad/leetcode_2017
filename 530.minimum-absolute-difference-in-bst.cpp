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
  int getMinimumDifference(TreeNode* root) {
    vector<int> nums;
    dfs(root, nums);

    int mdis = INT_MAX;
    for (int i=0; i+1<nums.size(); ++i) {
      mdis = min(mdis, nums[i+1]-nums[i]);
    }

    return mdis;
  }

  void dfs(TreeNode* o, vector<int>& nums) {
    if (!o) return;
    dfs(o->left, nums);
    nums.push_back(o->val);
    dfs(o->right, nums);
  }
};
