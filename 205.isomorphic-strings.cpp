#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, int> ms1, ms2;
    int sz = 0; 
    for (int i=0; i<s.size(); ++i) {
      if (ms1.count(s[i]) && ms2.count(t[i])) {
        if (ms1[s[i]] != ms2[t[i]]) return false;
        continue;
      }
      if (!ms1.count(s[i]) && !ms2.count(t[i])) {
        ms1[s[i]] = ms2[t[i]] = sz++;
      }

      if (ms1.count(s[i]) == 0 || ms2.count(t[i]) == 0) {
        return false;
      }
    }
    return true; 
  }
};
