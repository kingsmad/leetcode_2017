#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int lengthOfLastWord(string s) {
    int n = s.size();
    int ans = 0;
    for (int i=0; i<n; ) {
      while(s[i] == ' ') ++i;
      if (i == n) break;
      int q = i+1;
      while(q < n && s[q] != ' ') ++q; 
      ans = q - i;
      i = q;
    }
    return ans;
  }
};
