#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string parseTernary(string expression) {
    string s;
    int n = expression.size();
    for (int i=n-1; i>=0; --i) {
      s.push_back(expression[i]);
      if (s.size() < 5) continue;
      char v;
      if (check(s.substr(s.size()-5, 5), &v)) {
        s.erase(s.end() - 5, s.end());
        s.push_back(v);
      }
    }
    return s;
  }

  bool check(string s, char* ans) {
    reverse(s.begin(), s.end());
    if (s[0] != 'T' && s[0] != 'F') return false; 
    if (s[1] != '?') return false;
    if (s[3] != ':') return false;

    if (s[0] == 'T') *ans = s[2];
    else *ans = s[4];
    return true;
  }
};
