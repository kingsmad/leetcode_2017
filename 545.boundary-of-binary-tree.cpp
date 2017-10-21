#include <iostream>
#include <map>
#include <set>
#include <stack>
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
  void FindLeft(TreeNode* root, vector<int>& lv, set<int>& smp) {
    TreeNode* t = root;
    while(t) {
      if (smp.count(t->val) == 0) 
        lv.push_back(t->val);
      if (t->left) t = t->left;
      else t = t->right;
    }
  }

  void FindRight(TreeNode* root, vector<int>& lv, set<int>& smp) {
    TreeNode* t = root;
    while(t) {
      if (smp.count(t->val) == 0) 
        lv.push_back(t->val);
      if (t->right) t = t->right;
      else t = t->left;
    }
  }

  void FindLeaves(TreeNode* root, vector<int>& v, set<int>& smp) {
    if (!root) return;
    if (!root->left  && !root->right) {
      if (smp.count(root->val) == 0) v.push_back(root->val);
      return;
    }
    FindLeaves(root->left, v, smp);
    FindLeaves(root->right, v, smp);
  }

  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> lv, rv;
    set<int> smp;
    FindLeft(root, lv, smp);
    FindRight(root, rv, smp);

    for (int d : lv) smp.insert(d);
    for (int d : rv) smp.insert(d);

    vector<int> leaves;
    FindLeaves(root, leaves, smp);

    vector<int> ans;
    for (int d : lv) ans.push_back(d);
    for (int d : leaves) ans.push_back(d);
    for (int i=rv.size()-1; i>0; --i) ans.push_back(rv.at(i));

    return ans;
  }
};
