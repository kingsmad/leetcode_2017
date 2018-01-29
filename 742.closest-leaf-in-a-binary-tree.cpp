#include <assert.h>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
const int logmaxn = 20;
const int maxn = 1e3 + 10;
const int inf = 2e9 + 10;

struct LCA {
  int n, fa[maxn], L[maxn], anc[maxn][logmaxn];
  bool f = true;

  void init(int tn) {
    n = tn;
    memset(anc, -1, sizeof(anc));
    for (int i = 0; i < n; ++i)
      anc[i][0] = fa[i];
    for (int j = 1; (1 << j) < n; ++j) {
      for (int i = 0; i < n; ++i) {
        if (anc[i][j-1] != -1) {
          anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
      }
    }
  }

  int query(int p, int q) {
    if (L[p] < L[q]) swap(p, q);
    int log = 0;
    while(1<<(1+log) <= L[p]) ++log;
    
    for (int i=log; i>=0; --i) {
      if (L[p] - (1<<i) >= L[q]) {
        p = anc[p][i];
      }
    }

    if (p == q) return p;
    
    for (int i=log; i>=0; --i) {
      if (anc[p][i] != -1 && anc[p][i] != anc[q][i]) {
        p = anc[p][i];
        q = anc[q][i];
      }
    }

    assert(anc[p][0] == anc[q][0]);
    return anc[p][0];
  }

  int dis(int x, int y) {
    int pa = query(x, y);
    //printf("%d %d-> %d\n", x, y, pa);
    return L[x] - L[pa] + L[y] - L[pa];
  }
};

#ifdef ROACH_ONLINE_JUDGE
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
  struct LCA lca;
  unordered_map<TreeNode *, int> msid;
  unordered_map<int, TreeNode *> sid2node;
  int sid = 0;

public:
  int findClosestLeaf(TreeNode *root, int k) {
    init_sid();

    pre_traverse(root);
    dfs_fa(root, &lca.fa[0]);
    lca.fa[0] = -1;

    dfs_lv(root, 0, &lca.L[0]);

    lca.init(sid);

    check_fa();
    assert(Find(root, k) != 0);

    lca.query(1,2);

    int u = getsid(Find(root, k));
    int mi = INT_MAX;
    int ans = -1;
    vector<int> leaves;
    dfs_leaf(root, leaves);
    //for (int d : leaves) printf("%d ", d);
    for (int d : leaves) {
      int v = lca.dis(d, u);
      if (v < mi) {
        mi = v;
        ans = getnode(d)->val;
      }
    }

    return ans;
  }

  void pre_traverse(TreeNode* o) {
    if (!o) return;
    getsid(o);
    pre_traverse(o->left);
    pre_traverse(o->right);
  }

  TreeNode* Find(TreeNode *root, int k) {
    if (!root)
      return nullptr;
    if (root->val == k) return root;

    TreeNode* o = Find(root->left, k);
    if (o) return o;
    o = Find(root->right, k);
    return o;
  }

  void init_sid() {
    msid.clear();
    sid2node.clear();
    sid = 0;
  }

  int getsid(TreeNode *x) {
    if (msid.count(x))
      return msid.at(x);
    msid[x] = sid;
    sid2node[sid] = x;
    int ans = sid++;
    return ans;
  }

  inline TreeNode *getnode(int x) { return sid2node.at(x); }

  void dfs_fa(TreeNode *root, int *fa) {
    if (!root)
      return;

    if (root->left)
      fa[getsid(root->left)] = getsid(root);
    if (root->right)
      fa[getsid(root->right)] = getsid(root);

    dfs_fa(root->left, fa);
    dfs_fa(root->right, fa);
  }

  void dfs_lv(TreeNode *root, int v, int *L) {
    if (!root)
      return;
    L[getsid(root)] = v;
    dfs_lv(root->left, v + 1, L);
    dfs_lv(root->right, v + 1, L);
  }

  void dfs_leaf(TreeNode *root, vector<int> &leaves) {
    if (!root)
      return;
    if (!root->left && !root->right) {
      leaves.push_back(getsid(root));
      return;
    }
    dfs_leaf(root->left, leaves);
    dfs_leaf(root->right, leaves);
  }

  void check_fa() {
    for (int i=0; i<lca.n; ++i) {
      int u = lca.fa[i];
      if (u == -1) continue;
      assert(getnode(u)->left == getnode(i) || getnode(u)->right == getnode(i));
      assert(lca.L[u] + 1 == lca.L[i]);
    }

  }
};


#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  vector<TreeNode*> nodes(100, nullptr);
  for (int i=1; i<=10; ++i) nodes[i] = new TreeNode(i);
  nodes[1]->left = nodes[2];
  nodes[1]->right = nodes[3];
  nodes[3]->left = nodes[4];
  nodes[4]->left = nodes[6];
  nodes[6]->left = nodes[8];
  nodes[6]->right = nodes[9];
  nodes[3]->right = nodes[5];
  nodes[5]->right = nodes[7];
  nodes[7]->left = nodes[10];

  int target = 4;


  Solution sol;
  int ans = sol.findClosestLeaf(nodes[1], target);
  return 0 * printf("%d\n", ans);

}
#endif
