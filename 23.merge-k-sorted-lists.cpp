#include <bits/stdc++.h>
using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(){};
};
#endif

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](const ListNode* l1, const ListNode* l2) {
      return l1->val < l2->val;
    };

    set<ListNode*, decltype(cmp)> ms(cmp);

    for (ListNode* o : lists) {
      if (o) ms.insert(o);
    }

    ListNode nil(-1);
    ListNode* tail = &nil;
    while (ms.size()) {
      ListNode* p = *ms.begin();
      ms.erase(p);
      if (p->next) ms.insert(p->next);
      p->next = nullptr;

      tail->next = p;
      tail = p;
    }

    return nil.next;
  }
};

int main(int, char**) {
  ListNode n0 = 1, n1 = 1, n2 = 2, n3 = 1, n4 = 2, n5 = 2;
  n0.next = &n1;
  n1.next = &n2;
  n2.next = 0;
  n3.next = &n4;
  n4.next = &n5;
  n5.next = 0;

  vector<ListNode*> lists = {&n0, &n3};
  Solution sol;
  ListNode* ans = sol.mergeKLists(lists);

  ListNode* p = ans;
  while (p) {
    printf("%d ", p->val);
    p = p->next;
  }

  return 0;
}
