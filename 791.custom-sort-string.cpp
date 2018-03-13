#include <bits/stdc++.h>
using namespace std;
int dp[26][26], tag[26];

class Solution {
 public:
  string customSortString(string S, string T) {
    build(S);      
    auto fn = [&](char x, char y) -> bool {
      if (~dp[x-'a'][y-'a']) return dp[x-'a'][y-'a'];
      if (!(tag[x-'a'] && tag[y-'a'])) return tag[x-'a'];
      return x < y;
    };
    sort(T.begin(), T.end(), fn);

    return T;
  }

  void build(const string& s) {
    memset(dp, -1, sizeof(dp));
    memset(tag, 0, sizeof(tag));
    int n = s.size();
    for(int i=0; i<n; ++i) {
      for (int j=i+1; j<n; ++j) {
        dp[s[i]-'a'][s[j]-'a'] = 1;
        dp[s[j]-'a'][s[i]-'a'] = 0;
      }
    }

    for (char c : s) tag[c-'a'] = 1;
  }

};
