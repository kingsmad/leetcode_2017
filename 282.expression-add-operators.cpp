#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> ans;
using ll = long long;
class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    n = num.size();
    ans.clear();
    string path = "";
    for (int i = 1; i <= n; ++i) {
      if (num[0] == '0' && i > 1) break;
      path = num.substr(0, i);
      ll cv = stoll(path);
      dfs(i, cv, cv, path, num, target);
    }
    return ans;
  }

  void dfs(int p, ll tot, ll pre, const string path, const string& num,
           const int target) {
    if (p == n) {
      if (tot == target) ans.emplace_back(path);
      return;
    }

    ll cv = 0, q = p;
    while (q < n) {
      if (num.at(p) == '0' && q > p + 1) break;
      cv = 10 * cv + num.at(q++) - '0';
      const string cv_str = to_string(cv);

      if (num.at(p) == '0' && q > p + 1) break;
      dfs(q, tot + cv, cv, path + "+" + cv_str, num, target);

      dfs(q, tot - cv, -cv, path + "-" + cv_str, num, target);

      dfs(q, tot - pre + pre * cv, pre * cv, path + "*" + cv_str, num, target);
    }
  }
};
