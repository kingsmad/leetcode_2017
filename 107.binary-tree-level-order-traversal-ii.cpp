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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int>> ans;
      vector<TreeNode*> b[2];
      int cur = 0;
      if (root) b[cur].push_back(root);
      while(b[cur].size()) {
        vector<int> tmp;
        for (TreeNode* o : b[cur]) tmp.push_back(o->val);
        ans.emplace_back(tmp);

        b[!cur].clear();
        for (TreeNode* o : b[cur]) {
          if (o->left) b[!cur].push_back(o->left);  
          if (o->right) b[!cur].push_back(o->right);
        }
        cur = !cur;
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
