#include <iostream>
#include <string>
#include <vector>

#ifdef ROACH_ONLINE_JUDGE
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode nil(-1); nil.next = head;
    ListNode* p = &nil, *q = &nil;
    
    while(n--) q = q->next;

    while(q->next) {
      q = q->next;
      p = p->next;
    }

    p->next = p->next->next;
    return nil.next;
  }
};
