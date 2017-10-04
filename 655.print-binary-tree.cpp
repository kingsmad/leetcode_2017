#include <queue>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

struct Node {
  TreeNode* dptr;
  int lev, st, ed; 
  Node(TreeNode* t, int l, int s, int e) : dptr(t), lev(l), st(s), ed(e) { }

  inline TreeNode* left() { return dptr->left;}
  inline TreeNode* right() { return dptr->right;}
  inline int val() { return dptr->val;}
};

class Solution {
 public:
   int dfs(TreeNode* root) {
    if (!root) return 0;
    return max(dfs(root->left), dfs(root->right)) + 1;
   }

  vector<vector<string>> printTree(TreeNode* root) {
    int height = dfs(root);
    int n = pow(2, height) - 1;
    vector<vector<string>> ans(height, vector<string>(n, ""));
    queue<Node> mq;
    mq.push(Node(root, 0, 0, n));
    while(!mq.empty()) {
      Node o = mq.front();
      mq.pop();
      int md = (o.st + o.ed) / 2;
      char buf[10];
      sprintf(buf, "%d", o.val());
      ans[o.lev][md] = string(buf);

      if (o.left()) mq.push(Node(o.left(), o.lev+1, o.st, md));
      if (o.right()) mq.push(Node(o.right(), o.lev+1, md, o.ed));
    }

    return ans;
  }
};
