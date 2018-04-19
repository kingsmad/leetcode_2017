#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    set<int> ms;
    for (int d : nums) {
      ms.insert(d); 
      if (ms.size() > 3) ms.erase(ms.begin());
    }

    if (ms.size() < 3) return *ms.rbegin();
    return *ms.begin();
  }
};
