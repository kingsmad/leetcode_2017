#include <vector>
#include <string>
#include <map>
#include <queue>
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
  TreeNode* o;
  int lev;
  Node(TreeNode* t, int l) : o(t), lev(l) { }
};

class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    queue<Node> mq;
    mq.push(Node(root, 0));

    int lst_lev = -1, lst_v = -1;
    while(!mq.empty()) {
      Node x = mq.front();
      mq.pop();
      
      if (x.lev != lst_lev) {
        lst_lev = x.lev;
        lst_v = x.o->val;
      }
      if (x.o->left) mq.push(Node(x.o->left, x.lev + 1));  
      if (x.o->right) mq.push(Node(x.o->right, x.lev+1));
    }

    return lst_v;
  }
};
