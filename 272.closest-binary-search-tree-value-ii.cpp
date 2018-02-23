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
  vector<int> closestKValues(TreeNode* root, double target, int k) {
    deque<int> mq;
    stack<pair<TreeNode*, bool>> ms;
    ms.push({root, false});
    while (ms.size()) {
      TreeNode* o = ms.top().first;
      bool b = ms.top().second;
      ms.pop();
      if (!b) {
        if (o->right) ms.push({o->right, false});
        ms.push({o, true});
        if (o->left) ms.push({o->left, false});
        continue;
      }

      if (mq.size() < k) {
        mq.push_back(o->val);
      } else {
        if (abs(o->val - target) > abs(mq.front() - target))
          break;
        else {
          mq.push_back(o->val);
          mq.pop_front();
        }
      }
    }
    return vector<int>(mq.begin(), mq.end());
  }
};
