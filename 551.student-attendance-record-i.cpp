#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool checkRecord(string s) {
    int acnt = 0;        
    for (char c : s) if (c == 'A') ++acnt;
    if (acnt > 1) return false;

    for (int i=0; i+2<s.size(); ++i) {
      if (s[i] == 'L' && s[i+1] == 'L' && s[i+2] == 'L') return false;
    }

    return true;
  }
};
