#include <iostream>
#include <vector>

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
  ListNode* rotateRight(ListNode* head, int k) {
    int cnt = 0;
    for (ListNode* u=head; u; u=u->next) { ++cnt; }
    if (cnt == 0) return head;
    k = k % cnt;

    ListNode nil(-1);
    nil.next = head;

    ListNode* p = &nil, *q = &nil;
    while(k--) q = q->next;

    while(q && q->next) { p = p->next; q = q->next; }
    
    if (q) {
      q->next = nil.next;
      nil.next = p->next;
      p->next = nullptr;
    }

    return nil.next;
  }
};
