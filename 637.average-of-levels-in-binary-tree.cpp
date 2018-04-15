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
  vector<double> averageOfLevels(TreeNode* root) {
    double tot = 0;
    int cnt = 0, lev = -1;
    queue<pair<TreeNode*, int>> mq;
    mq.push({root, 0});

    vector<double> ans;
    while (mq.size()) {
      TreeNode* o = mq.front().first;
      int lv = mq.front().second;
      mq.pop();

      if (!o) continue;

      if (lv != lev) {
        if (cnt != 0) ans.push_back(tot / cnt);
        cnt = 0;
        lev = lv;
        tot = 0;
      }

      tot += o->val;
      ++cnt;

      mq.push({o->left, lv + 1});
      mq.push({o->right, lv + 1});
    }

    if (cnt != 0) ans.push_back(tot / cnt);
    return ans;
  }
};
