#include <set>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode*> ms;
    for (ListNode* p=head; p; p=p->next) {
      if (ms.count(p)) return p;
      ms.insert(p);
    }
    return nullptr;
  }
};
