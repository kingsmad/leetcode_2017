#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> ans;
    unordered_map<string, int> ms;
    for (int i = 0; i < words.size(); ++i) { ms[words[i]] = i; }

    for (int i = 0; i < words.size(); ++i) {
      const string s = words[i];
      for (int j = 0; j <= s.size(); ++j) {
        if (check(s, j, s.size())) {
          string tmp = s.substr(0, j);
          reverse(tmp.begin(), tmp.end());
          if (ms.count(tmp) > 0 && ms[tmp] != i) {
            ans.push_back({i, ms[tmp]});
          }
        }
        if (check(s, 0, j) && j > 0) {
          string tmp = s.substr(j, s.size());
          reverse(tmp.begin(), tmp.end());
          if (ms.count(tmp) > 0 && ms[tmp] != i) {
            ans.push_back({ms[tmp], i});
          }
        }
      }
    }
    return ans;
  }

  bool check(const string& s, int l, int r) {
    while (l < r) {
      if (s[l] != s[r - 1]) return false;
      ++l, --r;
    }
    return true;
  }
};
