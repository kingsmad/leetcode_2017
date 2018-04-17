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

  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int cnt1 = 0, cnt2 = 0;
    for (ListNode* p=headA; p; p=p->next) ++cnt1; 
    for (ListNode* p=headB; p; p=p->next) ++cnt2; 

    ListNode* p = headA, *q = headB; 
    while(cnt1 > cnt2) { p=p->next; --cnt1;}
    while(cnt1 < cnt2) { q=q->next; --cnt2;}
    
    while(p != q) {
      p = p->next;
      q = q->next;
    }

    return p; 
  }
};
