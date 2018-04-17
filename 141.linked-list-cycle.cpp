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
    bool hasCycle(ListNode *head) {
      if (!head) return false;
      ListNode* p = head, *q = head; 
      while(p && q && q->next) {
        p = p->next;
        q = q->next->next;
        if (p == q) return true;
      }
      return false;
    }
};
