#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
      int n = s.size(), ans = 0;        
      for (int i=0; i<n; ) {
        while(i <n && s[i] == ' ') ++i;
        if (i == n) break;
        int q = i + 1;
        while(q < n && s[q] != ' ') ++q;
        if (q > i) ++ans;
        i = q;
      }
      return ans;
    }
};
