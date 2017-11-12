#include <vector>
#include <string>
#include <map>

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
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    int cnt = 0; ListNode* t = head;
    while(t) { t = t->next; ++cnt;}
    cnt = cnt / 2;

    ListNode nil(-1); nil.next = head;
    ListNode* p = &nil;
    while(cnt--) p = p->next;

    ListNode* h2 = sortList(p->next);
    p->next = 0;
    ListNode* h1 = sortList(nil.next);

    nil.next = 0;
    ListNode* tail = &nil;

    while(h1 || h2) {
      if ((h1 && h2 && h1->val < h2->val) || (h1 && !h2)) {
          tail->next = h1;      
          tail = h1;
          h1 = h1->next;
          tail->next = 0;
      } else if ((h1 && h2 && h2->val <= h1->val) || (h2 && !h1)) {
          tail->next = h2;      
          tail = h2;
          h2 = h2->next;
          tail->next = 0;
      } else {
        printf("FUCKER\n");
      }
    }

    return nil.next;
  }
};
