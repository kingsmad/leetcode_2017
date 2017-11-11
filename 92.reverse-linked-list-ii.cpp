#include <vector>
#include <string>
#include <algorithm>

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
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode nil(-1);
    nil.next = head;
    
    ListNode* l = &nil;
    while(m-- > 1) l = l->next;

    ListNode* r = &nil;
    while(n-- > -1) r = r->next;

    ListNode* fucker = l->next;

    ListNode pier(-1);
    ListNode* p = l->next;
    while(p != r) {
      ListNode* tmp = p->next;
      p->next = pier.next;
      pier.next = p;
      p = tmp;
    }

    fucker->next = r;
    l->next = pier.next;

    return nil.next;
  }
};
