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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return calc(0, nums.size(), nums); 
  }

  TreeNode* calc(int st, int ed, const vector<int>& nums) {
    if (st == ed) return nullptr;
    int md = (st + ed) / 2;
    TreeNode* o = new TreeNode(nums[md]);
    o->left = calc(st, md, nums);
    o->right = calc(md+1, ed, nums);
    return o;
  }
};
