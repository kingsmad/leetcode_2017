#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> ms;
    for (int d : nums) ++ms[d];

    int ans = 0;
    for (int d : nums) {
      if (ms.count(d+1))
        ans = max(ans, ms[d] + ms[d+1]);
    }
    return ans;
  }
};
