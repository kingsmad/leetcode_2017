#include <vector>
#include <iostream>
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
 public:
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    int cnt = 0;
    for(ListNode* p=root; p; p=p->next) ++cnt;
    
    vector<int> nums(k, cnt/k);
    int rem = cnt - k * (cnt / k);
    for (int i=0; i<k; ++i) {
      if (rem <= 0) break;
      ++nums[i];
      --rem;
    }

    ListNode nil(-1); nil.next = root;

    vector<ListNode*> ans;
    for (int d : nums) {
      ListNode* p = &nil;
      while(d--) p = p->next;
      ans.push_back(nil.next);
      nil.next = p->next;
      p->next = nullptr;
    }

    return ans;
  }
};
