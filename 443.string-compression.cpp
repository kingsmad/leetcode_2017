#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int compress(vector<char>& chars) {
    int n = chars.size(); 
    string tmp;
    for (int i=0; i<n; ) {
      int q = i + 1;
      while(q < n && chars[q] == chars[i]) ++q;
      tmp += chars[i];    
      if (q - i > 1) tmp += to_string(q-i);
      i = q;
    }
    chars = vector<char>(tmp.begin(), tmp.end());
    return chars.size();
  }
};
