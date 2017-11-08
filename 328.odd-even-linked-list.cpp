#include <vector>
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
  ListNode* oddEvenList(ListNode* head) {
    if (!head) return nullptr;
    ListNode h1(-1), h2(-1);
    
    bool tuggle = true;
    while(head) {
      ListNode* tmp = head->next;
      if (tuggle) {
        ListNode* t = h1.next;
        head->next = t;
        h1.next = head;
      } else {
        ListNode* t = h2.next;
        head->next = t;
        h2.next = head;
      }
      head = tmp;
      tuggle = !tuggle;
    }

    ListNode* a1 = reverse(h1.next); 
    ListNode* a2 = reverse(h2.next);
    
    ListNode* p = a1; while(p->next) p = p->next;
    p->next = a2;
   
    return a1;
  }

  ListNode* reverse(ListNode* h) {
    ListNode nil(-1);
    while(h) {
      ListNode* t = h->next;
      h->next = nil.next;
      nil.next = h;
      h = t;
    }
    return nil.next;
  }
};
