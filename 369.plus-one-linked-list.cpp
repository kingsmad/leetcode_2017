#include <iostream>
#include <vector>
using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
 public:
  ListNode* plusOne(ListNode* head) {
    ListNode* h = Reverse(head); 

    int carry = 1;
    ListNode* p = h;
    while(p) {
      p->val += carry;
      carry = 0;
      if (p->val == 10) {
        p->val = 0;
        carry = 1;
      }

      p = p->next;
    }

    if (carry) {
      p = h;
      while(p->next) p = p->next;
      p->next = new ListNode(1);
    }

    return Reverse(h);
  }

  ListNode* Reverse(ListNode* h) {
    ListNode nil(-1);
    while(h) {
      ListNode* tmp = h->next;
      h->next = nil.next;
      nil.next = h;
      h = tmp;
    }
    
    return nil.next;
  }
};
