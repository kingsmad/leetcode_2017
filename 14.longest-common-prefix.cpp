#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string ans = strs.at(0); 
    for (const string& s : strs) {
      ans = cmp(ans, s); 
    }
    return ans;
  }
  const string cmp(const string& s1, const string& s2) {
    string ans;
    int n = min(s1.size(), s2.size());
    for (int i=0; i<n; ++i) {
      if (s1[i] == s2[i]) ans.push_back(s1[i]);
      else break;
    }
    return ans;
  }
};
