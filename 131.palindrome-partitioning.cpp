#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;

class Solution {
  map<string, vector<vector<string>>> ms;
  vector<vector<int>> pal;

 public:
  vector<vector<string>> partition(string s) {
    ms.clear();
    int n = s.size();
    pal = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    calc_pal(s);
    return calc(0, n, s);
  }

  void calc_pal(const string& s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) pal[i][i] = 1;
    for (int i = 0; i < n; ++i) pal[i][i + 1] = 1;

    for (int es = 2; es <= n; ++es) {
      for (int i = 0; i + es <= n; ++i) {
        if (s[i] != s[i + es - 1])
          pal[i][i + es] = 0;
        else
          pal[i][i + es] = pal[i + 1][i + es - 1];
      }
    }
  }

  vector<vector<string>> calc(int st, int ed, const string& s) {
    if (st == ed) return vector<vector<string>>();
    const string& sub = s.substr(st, ed - st);
    if (ms.count(sub)) return ms.at(sub);

    vector<vector<string>> ans;
    if (pal[st][ed])
      ans.push_back({sub}); /*handle whole interval independently*/
    for (int i = st + 1; i < ed; ++i) {
      if (pal[i][ed]) {
        vector<vector<string>> r = calc(st, i, s);
        for (vector<string>& vs : r) {
          vs.push_back(s.substr(i, ed - i));
          ans.push_back(vs);
        }
      }
    }

    ms.emplace(sub, ans);
    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  Solution sol;
  string s;
  cin >> s;
  vector<vector<string>> ans = sol.partition(s);
  for (const vector<string>& vs : ans) {
    for (const string& s : vs) { cout << s << " "; }
    cout << endl;
  }
}
#endif
