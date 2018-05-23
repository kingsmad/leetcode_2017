#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool areSentencesSimilar(vector<string>& words1, vector<string>& words2,
                           vector<pair<string, string>> pairs) {
    if (words1.size() != words2.size()) return false;
    set<pair<string, string>> ms(pairs.begin(), pairs.end());
    int n = words1.size();
    for (int i=0; i<n; ++i) {
      const string s1 = words1.at(i);
      const string s2 = words2.at(i);
      if (s1 != s2 && ms.count({s1, s2}) == 0 && ms.count({s2, s1}) == 0) return false;
    }
    return true;
  }
};
