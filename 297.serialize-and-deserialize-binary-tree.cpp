#include <bits/stdc++.h>

#ifdef ROACH_ONLINE_JUDGE
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

using namespace std;
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) return "#";
    string ans = to_string(root->val);
    ans += '(';
    ans += serialize(root->left);
    ans += ')';
    ans += '(';
    ans += serialize(root->right);
    ans += ')';
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream ss(data);
    return dfs(ss);
  }

  TreeNode* dfs(istringstream& ss) {
    TreeNode* o = nullptr;
    vector<TreeNode*> b;
    bool ok = true;
    while (ok && ss.peek() != EOF) {
      switch (ss.peek()) {
        case '#': ss.get(); break;
        case '(':
          ss.get();
          b.push_back(dfs(ss));
          break;
        case ')':
          ss.get();
          ok = false;
          break;
        default:
          int d;
          ss >> d;
          o = new TreeNode(d);
          break;
      }
    }

    if (b.size()) {
      o->left = b[0];
      o->right = b[1];
    }
    return o;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
}
#endif

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
