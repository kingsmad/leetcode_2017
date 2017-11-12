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
    ListNode nil(-1);
    ListNode* tail = &nil;
    int carry = 0;
    while(l1 || l2 || carry) {
      int v = 0;
      if (l1) { v += l1->val; l1 = l1->next;}
      if (l2) { v += l2->val; l2 = l2->next;}
      if (carry) { v += carry; carry = 0;}
      if (v > 9) { v -= 10; carry = 1;}
      
      ListNode* p = new ListNode(v);
      tail->next = p;
      tail = p;
    }

    return nil.next;
  }
};
