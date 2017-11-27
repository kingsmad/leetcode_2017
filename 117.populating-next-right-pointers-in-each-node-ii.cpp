#include <queue>
#include <vector>
#include <string>

using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
#endif

class Solution {
 public:
  void connect(TreeLinkNode *root) {
    if (!root) return;
    vector<TreeLinkNode*> nodes[2];
    int cur = 0, nxt = 1;
    nodes[cur].push_back(root);

    while(nodes[cur].size()) {
      for (int i=0; i+1<nodes[cur].size(); ++i) {
        nodes[cur][i]->next = nodes[cur][i+1];
      }
      nodes[cur].back()->next = nullptr;
      
      nodes[nxt].clear();
      for (TreeLinkNode* o : nodes[cur]) {
        if (o->left) nodes[nxt].push_back(o->left);
        if (o->right) nodes[nxt].push_back(o->right);
      }
      
      cur = !cur;
      nxt = !nxt;
    }
    
    return;
  }
};
