#include <bits/stdc++.h>
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
  string tree2str(TreeNode* t) {
    if (!t) return ""; 
    string s = "";
    dfs(t, s);
    return s;
  }

  void dfs(TreeNode* o, string& s) {
    s += to_string(o->val);
    if (o->left) {
      s += '(';
      dfs(o->left, s);
      s += ')';
    } else if (o->right) {
      s += "()";
    }

    if (o->right) {
      s += '(';
      dfs(o->right, s);
      s += ')';
    }
  }
};
