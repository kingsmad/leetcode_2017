#include <queue>
#include <iostream>
#include <vector>

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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<pair<TreeNode*, int> > mq;
    mq.push(make_pair(root, 0));
    int lv = 0, prev = root->val;

    while(!mq.empty()) {
      TreeNode* o = mq.front().first;
      int clv = mq.front().second;
      mq.pop();

      if (clv > lv) {
        ans.push_back(prev);
        lv = clv;
      }

      prev = o->val;

      if (o->left) mq.push(make_pair(o->left, clv+1));
      if (o->right) mq.push(make_pair(o->right, clv+1));
    }

    ans.push_back(prev);

    return ans;
  }
};
