#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 10;

class Solution {
 public:
  string minWindow(string s, string t) {
    int l = 0, q = 0, n = s.size();
    int al = -1, aq = inf;
    unordered_map<char, int> hs;
    for (char c : t) --hs[c];
    for (int i=0; i<n; ++i) {
      while(l < i) --hs[s[l++]];
      q = max(q, i);
      while(q < n && !check(hs)) ++hs[s[q++]];
      if (!check(hs)) break;
      if (q - l < aq - al) {
        aq = q, al = l; 
      }
    }

    return aq == inf ? "" : s.substr(al, aq-al);
  }

  bool check(unordered_map<char, int>& hs) {
    for (auto& pr : hs) if (pr.second < 0) return false;
    return true;
  }
};
