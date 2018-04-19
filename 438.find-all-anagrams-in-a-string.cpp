#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    int pn = p.size();
    unordered_map<int, int> ms;
    for (char c : p) --ms[c];
    int l = 0, r = 0;
    for (int i=0; i+pn<=s.size(); ++i) {
      while(l < i) --ms[s[l++]];
      while(r < i+pn) ++ms[s[r++]];
      bool ok = true;
      for (auto& pr :ms) {
        if (pr.second != 0) {
          ok = false;
          break;
        }
      }
      if (ok) ans.push_back(i);
    }

    return ans;
  }
};
