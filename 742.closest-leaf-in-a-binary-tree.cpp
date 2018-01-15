#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
const int logmaxn = 20;
const int maxn = 1e5 + 10;
struct LCA {
  int n, fa[maxn], L[maxn], anc[maxn][logmaxn];

  void init(int tn) {
    n = tn;
    memset(anc, -1, sizeof(anc));
    for (int i = 0; i < n; ++i) anc[i][0] = fa[i];
    for (int j = 1; (1 << j) < n; ++j) {
      for (int i = 0; i < n; ++i) { anc[i][j] = anc[anc[i][j - 1]][j - 1]; }
    }
  }

  int query(int x, int y) {
    if (L[x] < L[y]) swap(x, y);
    int k = 0;
    while ((1 << (k + 1)) <= L[x]) ++k;

    for (int i = k; i >= 0; --i)
      if (L[x] - (1 << i) >= L[y]) x = anc[x][i];

    for (int i = k; i >= 0; --i) {
      if (anc[x][i] != -1 && anc[y][i] != anc[x][i]) {
        x = anc[x][i];
        y = anc[y][i];
      }
    }

    return fa[x];
  }

  int dis(int x, int y) {
    int pa = query(x, y);
    return L[x] - pa + L[y] - pa;
  }
};

#ifdef ROACH_ONLINE_JUDGE
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
  struct LCA lca;
  unordered_map<TreeNode*, int> msid;
  unordered_map<int, TreeNode*> sid2node;
  int sid = 0;

 public:
  int findClosestLeaf(TreeNode* root, int k) {
    init_sid();
    dfs_fa(root, &lca.fa[0]);
    dfs_lv(root, 0, &lca.L[0]);

    lca.init(sid);

    int u = getsid(Find(root, k));
    int mi = INT_MAX;
    int ans = -1;
    vector<int> leaves;
    dfs_leaf(root, leaves);
    for (int d : leaves) {
      int v = lca.dis(d, u);
      if (v < mi) {
        mi = v;
        ans = getnode(d)->val;
      }
    }

    return ans;
  }

  TreeNode* Find(TreeNode* root, int k) {
    if (!root) return nullptr;
    if (root->val == k) return root;
    if (root->val < k) return Find(root->right, k);
    else return Find(root->left, k);
  }

  void init_sid() {
    msid.clear();
    sid2node.clear();
    sid = 0;
  }

  int getsid(TreeNode* x) {
    if (msid.count(x)) return msid.at(x);
    int ans = (msid[x] = sid++);
    sid2node[ans] = x;
    return ans;
  }

  inline TreeNode* getnode(int x) { return sid2node.at(x); }

  void dfs_fa(TreeNode* root, int* fa) {
    if (!root) return;
    if (root->left) fa[getsid(root->left)] = getsid(root);
    if (root->right) fa[getsid(root->right)] = getsid(root);
    dfs_fa(root->left, fa);
    dfs_fa(root->right, fa);

    
  }

  void dfs_lv(TreeNode* root, int v, int* L) {
    if (!root) return;
    L[getsid(root)] = v;
    dfs_lv(root->left, v + 1, L);
    dfs_lv(root->right, v + 1, L);
  }

  void dfs_leaf(TreeNode* root, vector<int>& leaves) {
    if (!root) return;
    if (!root->left && !root->right) { leaves.push_back(getsid(root)); return;}
    dfs_leaf(root->left, leaves);
    dfs_leaf(root->right, leaves);
  }
};
