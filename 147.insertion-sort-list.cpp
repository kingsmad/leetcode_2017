#include <vector>
#include <string>
#include <map>

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
  ListNode* insertionSortList(ListNode* head) {
    ListNode ans(-1);
    for (ListNode* p=head; p; ) {
      ListNode* tmp = p->next;
      ListNode* q = &ans;
      while(q && q->next && p->val > q->next->val) q = q->next;
      p->next = q->next;
      q->next = p;
      p = tmp;
    }

    return ans.next;
  }
};
