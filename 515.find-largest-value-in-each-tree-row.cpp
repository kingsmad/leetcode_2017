#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
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
  vector<int> largestValues(TreeNode *root) {
    map<TreeNode*, int> n2lv; 
    queue<TreeNode*> mq;
    if (root) { n2lv.emplace(root, 0); mq.push(root); }

    while(!mq.empty()) {
      TreeNode* o = mq.front();
      int l = n2lv.at(o);
      mq.pop();

      if (o->left) { n2lv.emplace(o->left, l+1); mq.push(o->left);}
      if (o->right) { n2lv.emplace(o->right, l+1); mq.push(o->right);}
    }

    map<int, int> ans;
    for (auto it=n2lv.begin(); it != n2lv.end(); ++it) {
      int v = it->first->val, l = it->second;
      if (ans.count(l) == 0) ans.emplace(l, INT_MIN);
      ans[l] = max(v, ans[l]);
    }

    vector<int> vans;
    for (auto it=ans.begin(); it!=ans.end(); ++it) {
      vans.push_back(it->second);
    }

    return vans;
  }
};
