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
  map<int, int> ms1, ms2;
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    ms1.clear();
    ms2.clear();
    for (int i=0; i<preorder.size(); ++i) ms1[preorder.at(i)] = i;
    for (int i=0; i<inorder.size(); ++i) ms2[inorder.at(i)] = i;
    return calc(0, preorder.size(), 0, inorder.size(), preorder, inorder);
  }

  TreeNode* calc(int pst, int ped, int ist, int ied, const vector<int>& preorder,
                const vector<int>& inorder) {
    if (pst == ped) return nullptr;
    TreeNode* o = new TreeNode(preorder.at(pst));

    int p2 = ms2[o->val];
    o->left = calc(pst+1, pst+1+p2-ist, ist, p2, preorder, inorder);
    o->right = calc(pst+1+p2-ist, ped, p2+1, ied, preorder, inorder);
    return o;
  }
};
