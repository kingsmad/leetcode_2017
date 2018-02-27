#include <bits/stdc++.h>
using namespace std;

class Solution {
  unordered_set<string> ms;
 public:
  vector<string> wordsAbbreviation(vector<string>& dict) {
    ms.clear();
    vector<string> ans;
    for (const string& s : dict) {
      bool ok = false;
      int n = s.size();
      for (int i = 1; i+1 < n && !ok; ++i) {
        const string tmp = s.substr(0, i) + to_string(n - i - 1) + s.back();
        if (tmp.size() >= s.size()) { break;}
        if (ms.count(tmp) == 0) {
          ok = true;
          ans.push_back(tmp);
          ms.emplace(tmp);
          break;
        }
      }
      if (!ok) { ms.emplace(s); ans.push_back(s);}
    }

    return ans;
  }
};
