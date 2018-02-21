#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> ms;
    for (int d : nums) ms.insert(d);

    int ans = 0;
    for (int d : nums) {
      if (ms.count(d) == 0) continue;
      int cnt = 0;
      int p = d;
      while(ms.count(p)) ++p;
      int q = d - 1; 
      while(ms.count(q)) --q;
      ++q;
      for (int i=q; i<p; ++i) ms.erase(i);
      ans = max(ans, p - q); 
    }

    return ans;
  }
};
