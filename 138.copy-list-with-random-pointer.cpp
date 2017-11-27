#include <cstring>
#include <vector>
#include <string>
using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
#endif

class Solution {

 public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode nil(-1);    
    nil.next = head;

    for (RandomListNode* p = head; p; ) {
      RandomListNode* tmp = p->next;
      RandomListNode* o = new RandomListNode(-1); 
      memcpy(o, p, sizeof(RandomListNode));
      p->next = o;
      p = tmp;
    }

    for (RandomListNode* p=head; p; ) {
      if (p->next->random) p->next->random = p->next->random->next;
      p = p->next->next;
    }

    RandomListNode ans(-1); RandomListNode* tail = &ans;
    for (RandomListNode* p=head; p; ) {
      RandomListNode* tmp = p->next->next;
      tail->next = p->next; 
      tail = tail->next;
      p->next->next = 0;
      p->next = tmp;
      p = tmp;
    }

    return ans.next;
  }
};
