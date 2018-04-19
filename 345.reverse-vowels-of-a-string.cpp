#include <bits/stdc++.h>
using namespace std;
const char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
bool check(char c) {
  for (int i=0; i<5; ++i) if (c == vowel[i] || c == vowel[i] + ('A' -'a')) return true;
  return false;
}

class Solution {
public:
  string reverseVowels(string s) {
    int n = s.size();
    int p = 0, q = n-1;
    while(p < q) {
      while(p < q && !check(s[p])) ++p;
      while(p < q && !check(s[q])) --q;
      if (p == q) break;
      swap(s[p++], s[q--]);
    }
    return s;
  }
};
