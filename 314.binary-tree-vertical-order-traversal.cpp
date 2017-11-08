#include <climits>
#include <stack>
#include <map>
#include <queue>
#include <vector>
#include <iostream>

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
  map<TreeNode*, int> node2col;
 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (!root) return vector<vector<int>>();
    node2col[root] = 0;
    stack<TreeNode*> ms;
    ms.push(root);
    while(!ms.empty()) {
      TreeNode* o = ms.top();
      ms.pop();

      int v = node2col.at(o);
      if (o->left) { node2col.emplace(o->left, v-1); ms.push(o->left);}
      if (o->right) { node2col.emplace(o->right, v+1); ms.push(o->right);}
    }

    int mn = INT_MAX, mx = INT_MIN;
    for (auto& p : node2col) { mn = min(mn, p.second); mx = max(mx, p.second);}

    vector<vector<int> > ans(mx-mn+1, vector<int>());

    queue<TreeNode*> mq;
    mq.push(root);
    while(!mq.empty()) {
      TreeNode* o = mq.front();
      mq.pop();

      int c = node2col.at(o);
      ans[c-mn].push_back(o->val);
      if (o->left) mq.push(o->left);
      if (o->right) mq.push(o->right);
    }

    return ans;
  }
};
