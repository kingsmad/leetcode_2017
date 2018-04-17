#include <bits/stdc++.h>
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode nil(-1);
    ListNode* tail = &nil;
    while(l1 || l2) {
      if (!l2 || (l1 && l1->val < l2->val)) {
        ListNode* tmp = l1->next;
        l1->next = nullptr;
        tail->next = l1;
        tail = l1;
        l1 = tmp;
      } else {
        ListNode* tmp = l2->next;
        l2->next = nullptr;
        tail->next = l2;
        tail = l2;
        l2 = tmp;
      }
    }
    return nil.next;
  }
};
