#include <iostream>
#include <vector>

#ifdef ROACH_ONLINE_JUDGE
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

#endif
class Solution {
public:
  ListNode* middleNode(ListNode* head) {
    int cnt = 0;
    for (ListNode* p=head; p; p=p->next) ++cnt;

    cnt = cnt/2;
    ListNode* p = head;
    while(cnt-- && p) p = p->next;
    return p;
  }
};
