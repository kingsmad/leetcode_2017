#include <iostream>
#include <vector>
#include <string>

using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
  ListNode* hd;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
      hd = head; 
    }
    
    /** Returns a random node's value. */
    int getRandom() {
      int cnt = 1;
      ListNode* p = hd;
      int v = p->val;
      while(p) {
        if (rand() % cnt == 0) v = p->val;
        p = p->next;
        ++cnt;
      }
      
      return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
