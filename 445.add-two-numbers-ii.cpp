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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);

    ListNode nil(-1);
    ListNode* tail = &nil;
    int carry = 0;
    ListNode* p = l1, *q = l2;
    
    while(p || q || carry) {
      int v = 0;
      if (p) { v += p->val; p = p->next;}
      if (q) { v += q->val; q = q->next;}
      if (carry) { v += carry; carry = 0;}
      if (v >= 10) { v -= 10; carry = 1;}

      ListNode* x = new ListNode(v);
      tail->next = x;
      tail = x;
      tail->next = 0;
    }
    
    return reverse(nil.next);
  }

  ListNode* reverse(ListNode* hd) {
    ListNode nil(-1);
    while(hd) {
      ListNode* tmp = hd->next;
      hd->next = nil.next;
      nil.next = hd;
      hd = tmp;
    }
    return nil.next;
  }
};
