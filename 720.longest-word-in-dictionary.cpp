#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string longestWord(vector<string>& words) {
    auto cmp = [&](const string s1, const string s2) {
      if (s1.size() != s2.size()) return s1.size() < s2.size(); 
      return s1 < s2;
    };
    sort(words.begin(), words.end(), cmp);
    vector<string> vc;
    set<string> ms;
    for (const string s : words) {
      if (s.size() == 1 || ms.count(s.substr(0, s.size()-1)) > 0) {
        ms.insert(s);
        vc.push_back(s);
      }
    }

    if (ms.empty()) return "";

    int p = vc.size() - 1;
    while(p >= 0 && vc[p].size() == vc.back().size()) --p;
    ++p;
    return vc[p];
  }

};
