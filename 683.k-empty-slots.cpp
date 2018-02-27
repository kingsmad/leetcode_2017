#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  int kEmptySlots(vector<int>& flowers, int k) {
    set<int> ms;

    for (int d : flowers) {
      ms.insert(d);
      auto it = ms.find(d);

      if (it != ms.begin()) {
        --it; if (*it + k + 1== d) return ms.size();  
        ++it;
      }

      ++it;
      if (it != ms.end()) {
        if (*it - k - 1== d) return ms.size();
      }

    }
    return -1;
  }
};
