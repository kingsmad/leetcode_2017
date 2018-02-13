#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int calculate(string s) {
    vector<int> ans(1, 0);
    int cur = 0;
    char op = '+';
    s.push_back('+');

    for (char c : s) {
      if (c == ' ') continue;
      if (isdigit(c)) {
        cur = 10 * cur + c - '0';
      } else {
        if (op == '+') {
          ans.push_back(cur);
        } else if (op == '-') {
          ans.push_back(-cur);
        } else if (op == '*') {
          int& x=  ans.back();
          x = x * cur;
        } else if (op == '/') {
          int& x = ans.back();
          x = x / cur;
        }
        cur = 0;
        op = c;
      }
    }

    int res = 0;
    for (int d : ans) res += d;
    return res;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  string s;
  cin >> s;
  Solution sol;
  int ans = sol.calculate(s);
  return 0 * printf("%d\n", ans);
}
#endif
