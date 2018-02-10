#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canTransform(string start, string end) {
    if (start.size() != end.size()) return false;
    int n = start.size();
    
    int r1 = 0, r2 = 0, l1 = 0, l2 = 0;
    for (int i=0; i<n; ++i) {
      if (start[i] == 'R') ++r1;
      if (end[i] == 'R') { ++r2; if (r2 > r1) return false;}
      if (end[i] == 'L') { if (r2 < r1) return false;}
    }

    for (int i=n-1; i>=0; --i) {
      if (start[i] == 'L') ++l1;
      if (end[i] == 'L') { ++l2; if (l2 > l1) return false;}
      if (end[i] == 'R') { if (l2 < l1) return false; }
    }
    
    return (r1 == r2 && l1 == l2);
  }
};
