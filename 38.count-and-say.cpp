#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    string str = "1";
    while(--n) {
      string tmp;
      for (int i=0; i<str.size(); ) {
        int q = i + 1;
        while(q < str.size() && str[q] == str[i]) ++q;
        tmp += to_string(q - i);
        tmp += str[i];
        i = q;
      }
      str = tmp;
    }
    return str;
  }
};
