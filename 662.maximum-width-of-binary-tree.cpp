/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Node {
  TreeNode* dptr;
  int lev;
  Node(TreeNode* p, int l, int v) : dptr(p), lev(l) {
    if (p) p->val = v;
  }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
      queue<Node> mq;           
      map<int, pair<int, int>> smp;
      mq.push(Node(root, 0, 0));
      while(!mq.empty()) {
        Node t = mq.front();
        mq.pop();
        if (smp.count(t.lev) == 0) {
          smp.emplace(t.lev, make_pair(t.dptr->val, t.dptr->val));
        } else {
          int l = smp.at(t.lev).first, r = smp.at(t.lev).second;
          l = min(l, t.dptr->val);
          r = max(r, t.dptr->val);
          smp.erase(t.lev);
          smp.emplace(t.lev, make_pair(l, r));
        }
        if (t.dptr->left) mq.push(Node(t.dptr->left, t.lev+1, 2*t.dptr->val+1));
        if (t.dptr->right) mq.push(Node(t.dptr->right, t.lev+1, 2*t.dptr->val+2));
      }

      int ans = 0;
      for (auto it=smp.begin(); it!=smp.end(); ++it) {
        pair<int, int>& p = it->second;
        ans = max(p.second - p.first, ans);
      }

      return ans + 1;
    }
};
