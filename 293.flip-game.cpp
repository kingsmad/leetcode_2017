#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> generatePossibleNextMoves(string s) {
    vector<string> ans;
    int n = s.size();
    for (int i=0; i+1<n; ++i) {
      if (s[i] == '+' && s[i+1] == '+') {
        ans.emplace_back(s.substr(0, i) + "--" + s.substr(i+2, n));
      }
    }
    return ans;
  }
};
