#include <math.h>
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
  int countNodes(TreeNode* root) {
    if (!root) return 0;

    int lcnt = 0, rcnt = 0;
    TreeNode* p = root, *q = root;
    while(p) { p=p->left; ++lcnt;}
    while(q) { q=q->right; ++rcnt;}
    if (lcnt == rcnt) return pow(2, lcnt) - 1;

    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};
