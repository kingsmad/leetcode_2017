#include <iostream>
#include <vector>
#include <string>

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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode nil(-1);
    ListNode* tail = &nil;

    ListNode* p = head;
    while(p) {
      ListNode* q = p->next;
      while(q && q->val == p->val) q = q->next;

      if (p->next == q) {
        tail->next = p;
        tail = p;
        tail->next = 0;
      }

      p = q;
    }

    return nil.next;
  }
};
