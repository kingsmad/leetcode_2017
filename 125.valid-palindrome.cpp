#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    int n = s.size();
    int p = 0, q = n - 1;
    while (p<q) {
      while (p < q && (!isalpha(s[p]) && !isdigit(s[p]))) ++p;
      while (q > p && (!isalpha(s[q]) && !isdigit(s[q]))) --q;
      if (p == q) break;
      char a = s[p], b = s[q];
      if (isupper(a)) a = a - 'A' + 'a';
      if (isupper(b)) b = b - 'A' + 'a';
      if (a != b) return false;
      ++p, --q;
    }

    return true;
  }
};
