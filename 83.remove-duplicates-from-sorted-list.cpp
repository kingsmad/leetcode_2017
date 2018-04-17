#include <bits/stdc++.h>
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
    nil.next = head;
    for (ListNode *p = nil.next; p; ) {
      ListNode* q = p->next;
      while(q && q->val == p->val) q = q->next;
      p->next = q;
      p = q;
    }
    return nil.next;
  }
};
