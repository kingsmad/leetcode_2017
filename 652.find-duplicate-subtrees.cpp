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
  map<TreeNode*, string> ptr2str;
  map<string, vector<TreeNode*>> smp;
 public:
  string dfs(TreeNode* root) {
    if (!root) return "";
    if (ptr2str.count(root) > 0) return ptr2str.at(root);

    string s1 = dfs(root->left);
    string s2 = dfs(root->right);
    return s1 + "#" + s2 + "#" + Int2String(root->val);
  }

  void dfs1(TreeNode* root) {
    if (!root) return;
    const string str = dfs(root);
    smp[str].push_back(root);

    dfs1(root->left);
    dfs1(root->right);
  }

  string Int2String(int x) {
    char buf[20];
    sprintf(buf, "%d", x);
    return string(buf);
  }

  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    smp.clear();
    ptr2str.clear();

    dfs1(root);

    vector<TreeNode*> ans;
    for (auto it = smp.begin(); it != smp.end(); ++it) {
      vector<TreeNode*>& vs = it->second;
      if (vs.size() > 1) ans.push_back(vs.front());
    }

    return ans;
  }
};
