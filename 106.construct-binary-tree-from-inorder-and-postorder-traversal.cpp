#include <assert.h>
#include <map>
#include <string>
#include <vector>

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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    return calc(0, n, 0, n, inorder, postorder);
  }

  TreeNode* calc(int st1, int ed1, int st2, int ed2, const vector<int>& inorder,
                 const vector<int>& postorder) {
    if (st1 == ed1 || st2 == ed2) return nullptr;
    int v = postorder.at(ed2-1);
    TreeNode* root = new TreeNode(v);
    //int p = lower_bound(inorder.begin() + st1, inorder.begin() + ed1, v) - 
     //                   inorder.begin();
    int p = st1;
    while(p < ed1 && inorder.at(p) != v) ++p;
    assert(inorder.at(p) == v);
    root->left = calc(st1, p, st2, st2+p-st1, inorder, postorder);
    root->right = calc(p+1, ed1, ed2-1-(ed1-p-1), ed2-1, inorder, postorder);
    return root;
  }
};
