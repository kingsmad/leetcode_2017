#include <climits>
#include <map>
#include <string>
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

class Solution {
 public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    map<int, int> sum;  
    dfs(root, sum);
    
    vector<int> ans;
    int mv = INT_MIN;
    for (auto& p : sum) {
      mv = max(mv, p.second);
    }
    
    for(auto& p : sum) {
      if (mv == p.second) ans.push_back(p.first);
    }

    return ans;
  }

  int dfs(TreeNode* root, map<int, int>& sum) {
    if (!root) return 0;
    int t = root->val + dfs(root->left, sum) + dfs(root->right, sum);
    ++sum[t];

    return t;
  }
};
