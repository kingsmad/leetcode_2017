#include <iostream>
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
  ListNode* swapPairs(ListNode* head) {
    ListNode nil(-1);    
    nil.next = head;

    ListNode* p = &nil;
    while(p && p->next && p->next->next) {
      ListNode* q = p->next->next->next;
      ListNode* t1 = p->next;
      ListNode* t2 = p->next->next;
      p->next = t2;
      t2->next = t1;
      t1->next = q;
      p = t1;
    }
    
    return nil.next;
  }
};
