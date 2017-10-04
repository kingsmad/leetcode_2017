#include <assert.h>
#include <map>
#include <math.h>
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

const int maxn = 1e3 + 10;
class Solution {
  int st[maxn][31];
  map<int, int> v2id;
  public:
    void InitRmq(vector<int>& nums) {
      int n = nums.size();
      v2id.clear();
      for (int i=0; i<n; ++i) v2id[nums[i]] = i;
      for (int i=0; i<n; ++i) st[i][0] = nums[i];     
      for (int j=1; (1<<j)<=n; ++j) {
        for (int i=0; i+(1<<j)<=n; ++i) {
          st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
      }
    }

    int query(int l, int r) {
      int k = 0;
      while((1<<(k+1)) <= r - l) ++k;
      return max(st[l][k], st[r-(1<<k)][k]);
    }

    TreeNode* dfs(int l, int r, vector<int>& nums) {
      int maxv = query(l, r);
      TreeNode* o = new TreeNode(maxv);
      o->left = o->right = nullptr;

      int md = v2id.at(maxv);
      assert(l <= md && r >= md);

      if (l < md) o->left = dfs(l, md, nums);
      if (r > md+1) o->right = dfs(md+1, r, nums);
      return o;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      InitRmq(nums);
      int n = nums.size();
      TreeNode* root = dfs(0, n, nums);
      return root;
    }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  Solution sol;
  int n; scanf("%d", &n);
  vector<int> nums;
  for (int i=0; i<n; ++i) {
    int d; scanf("%d", &d);
    nums.push_back(d);
  }

  TreeNode* root = sol.constructMaximumBinaryTree(nums);
  return 0;
}

#endif
