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
  void reorderList(ListNode* head) {
    if (!head || !head->next) return;

    ListNode h1(-1), h2(-1);
    h1.next = head;

    int cnt = 0; for (ListNode* p=head; p; p=p->next) ++cnt;
    cnt = cnt / 2;
    ListNode* u = &h1;
    while(cnt--) u = u->next;
    
    for (ListNode* p=u->next; p; ) {
      ListNode* tmp = p->next;
      p->next = h2.next;
      h2.next = p;
      p = tmp;
    }

    u->next = nullptr;
    
    ListNode ans(-1);
    ListNode* tail = &ans;
    
    ListNode* p = h1.next, *q = h2.next;
    while(p || q) {
      if (p) {
        tail->next = p;
        tail = p;
        p = p->next;
        tail->next = 0;
      }
      if (q) {
        tail->next = q;
        tail = q;
        q = q->next;
        tail->next = 0;
      }
    }

    head = ans.next;
  }
};
