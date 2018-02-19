#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
      int p = 0, q = 0; 
      int n1 = s.size(), n2 = t.size();
      if (abs(n1-n2) > 1) return false;
      
      int sta = 0;
      while(p < n1 || q < n2) {
        if (s[p] == t[q]) {
          ++p, ++q;
          continue;
        }
        if (sta > 0) return false;
        sta = 1;
        if (n1 > n2) ++p;
        else if (n1 < n2) ++q;
        else { ++p, ++q;}
      }

      return sta == 1;
    }
};
