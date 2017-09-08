/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Comp {
 public:
  bool operator()(const ListNode* p, const ListNode* q) const {
    return p->val < q->val;
  }
};

class Solution {
  public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Comp> mq;
    for (int i=0; i<lists.size(); ++i) {
      ListNode* p = lists[i];
      while(p) { mq.push(p); p=p->next;}
    }

    ListNode nil(-1);
    while(!mq.empty()) {
      ListNode* o = mq.top();
      mq.pop();
      o->next = nil.next;
      nil.next = o;
    }
   
    return nil.next;
  }
};
