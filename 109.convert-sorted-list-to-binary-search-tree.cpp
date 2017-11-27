#include <map>
#include <string>
#include <vector>

using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

vector<ListNode*> nodes;
class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    nodes.clear();
    for (ListNode* p=head; p; p=p->next) nodes.push_back(p);
    return Calc(0, nodes.size());
  }

  TreeNode* Calc(int l, int r) {
    if (l == r) return nullptr;
    int md = (l+r)/2;

    TreeNode* o = new TreeNode(nodes.at(md)->val);
    o->left = Calc(l, md);
    o->right = Calc(md+1, r);
    return o;
  }
};
