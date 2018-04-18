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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode nil(-1);    
    ListNode* tail = &nil;
    for (ListNode* p=head; p; ) {
      ListNode* q = p->next;
      p->next = nullptr;
      if (p->val != val) {
        tail->next = p;
        tail = p;
      }
      p = q;
    }
    return nil.next;
  }
};
