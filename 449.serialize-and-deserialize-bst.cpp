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

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) return " #";  
    string ans = " " + to_string(root->val);
    return ans + serialize(root->left) + serialize(root->right); 
  }

  TreeNode* dfs(istringstream& ss) {
    string str; ss >> str;
    if (str == "#") return nullptr;
    TreeNode* root = new TreeNode(stoi(str));
    root->left = dfs(ss);
    root->right = dfs(ss);
    return root;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream ss(data); 
    return dfs(ss);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
