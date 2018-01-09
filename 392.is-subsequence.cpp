#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int n1 = s.size(), n2 = t.size(); 
    int p = 0, q = 0;
    while(p < n1 && q < n2) {
      if (s[p] == t[q]) ++p; 
      ++q;
    }
    return p == n1;
  }
};
