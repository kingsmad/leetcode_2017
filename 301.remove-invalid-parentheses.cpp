#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void dfs(string s, char ch, int lst) {
    for (int i = 0, cnt = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == ')') s[i] == ch ? cnt++ : cnt--;
      if (cnt <= 0) continue;
      for (int j = lst; j <= i; j++) {
        if (s[j] == ch && (j == lst || s[j - 1] != ch))
          dfs(s.substr(0, j) + s.substr(j + 1), ch, j);
      }
      return;
    }
    reverse(s.begin(), s.end());
    if (ch == ')') return dfs(s, '(', 0);
    ans.push_back(s);
  }

  vector<string> removeInvalidParentheses(string s) {
    ans.clear();
    dfs(s, ')', 0);
    return ans;
  }

 private:
  vector<string> ans;
};
