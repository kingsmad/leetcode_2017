#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string ans = strs[0];      
    for (int i=1; i<strs.size(); ++i) {
      int j = 0;
      for (; j<ans.size(); ++j) {
        if (ans[j] != strs[i][j]) break;
      }
      ans = ans.substr(0, j);
    }
    return ans;
  }
};
