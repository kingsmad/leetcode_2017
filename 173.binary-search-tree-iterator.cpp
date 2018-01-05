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

class BSTIterator {
  vector<int> nums;
  int ps;
public:
    BSTIterator(TreeNode *root) {
      nums.clear();
      ps = 0;
      traverse(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      return ps < nums.size();
    }

    /** @return the next smallest number */
    int next() {
      return nums.at(ps++); 
    }

    void traverse(TreeNode* root) {
      if (!root) return;
      if (root->left) traverse(root->left);
      nums.push_back(root->val);
      if (root->right) traverse(root->right);
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
