#include <stack>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> ms; 
    const int n = nums.size();
    vector<int> ans(n, -1);
    for (int i=0; i<n; ++i) {
      while(!ms.empty() && nums.at(ms.top()) < nums.at(i)) {
        int x = ms.top(); ms.pop();
        ans[x] = i;
      }
      ms.push(i);
    }

    for (int i=0; i<n; ++i) {
      while(!ms.empty() && nums.at(ms.top()) < nums.at(i)) {
        int x = ms.top(); ms.pop();
        ans[x] = i;
      }
    }

    for (int i=0; i<n; ++i) if (ans.at(i) != -1) ans[i] = nums.at(ans[i]);

    return ans;
  }
};
