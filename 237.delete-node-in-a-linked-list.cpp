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
  void deleteNode(ListNode* node) {
    ListNode* p = node;
    while(p && p->next) {
      swap(p->val, p->next->val);
      if (p->next->next) p = p->next;
      else break;
    }
    p->next = nullptr;
  }
};
