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
  bool isPalindrome(ListNode* head) {
    if (!head) return true;
    int cnt = 0;
    for (ListNode* p = head; p; p=p->next) ++cnt;
    cnt = (cnt & 1) ? cnt/2 : cnt/2-1;
    ListNode* p = head;
    while(cnt--) p = p->next;

    ListNode* hd2 = p->next;
    p->next = nullptr;

    ListNode nil(-1); 
    for (ListNode* q=hd2; q; ) {
      ListNode* tmp = q->next;
      q->next = nil.next;
      nil.next = q;
      q = tmp;
    }

    ListNode* u = head, *v = nil.next;
    while(u && v) {
      if (u->val != v->val) return false;
      u = u->next;
      v = v->next;
    }

    return true;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  ListNode a(1), b(0), c(1); 
  a.next = &b;
  b.next = &c;
  Solution sol;
  bool ok  = sol.isPalindrome(&a);
  if (ok) printf("YES\n");
  else printf("NO\n");
  return 0;
}
#endif
