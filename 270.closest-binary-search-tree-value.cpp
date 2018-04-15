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
  int closestValue(TreeNode* root, double target) {
    vector<double> vec;      
    dfs(root, vec);

    int p = lower_bound(vec.begin(), vec.end(), target) - vec.begin();
    if (p == vec.size()) p = vec.size() - 1;
    if (p > 0) {
      int q = p - 1;
      if (target - vec[q] < vec[p] - target) p = q;
    }

    return vec[p];
  }

  void dfs(TreeNode* o, vector<double>& vec) {
    if (!o) return;
    dfs(o->left, vec);
    vec.push_back(o->val);
    dfs(o->right, vec);
  }
};
