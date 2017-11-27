#include <iostream>
#include <vector>
#include <set>

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
  ListNode* partition(ListNode* head, int x) {
    ListNode h1(-1); ListNode* ht1 = &h1;
    ListNode h2(-1); ListNode* ht2 = &h2;

    for (ListNode* p=head; p; ) {
      ListNode* tmp = p->next;
      if (p->val < x) {
        ht1->next = p;
        ht1 = p;
        p = p->next;
        ht1->next = 0;
      } else {
        ht2->next = p;
        ht2 = ht2->next;
        p = p->next;
        ht2->next = 0;
      }
    }

    ht1->next = h2.next;
    
    return h1.next;
  }
};
