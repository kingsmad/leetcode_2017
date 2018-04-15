#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool validPalindrome(string s) {
    int n = s.size(), cnt = 0;
    int p = 0, q = n - 1;
    while (p < q) {
      if (s[p] != s[q]) return check(p + 1, q, s) || check(p, q - 1, s);
      ++p, --q;
    }
    return true;
  }

  bool check(int p, int q, const string& s) {
    while (p < q) {
      if (s[p] != s[q]) return false;
      ++p, --q;
    }
    return true;
  }
};
