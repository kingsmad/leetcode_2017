#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string reverseStr(string s, int k) {
    if (k == 0) return s;
    int n = s.size();
    for (int i=0; i<n; ) {
      int ed = min(n, i + k); 
      reverse(s.begin()+i, s.begin()+ed);
      i = min(n, i+2*k);
    }
    return s;
  }
};
