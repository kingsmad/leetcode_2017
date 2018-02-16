#include <bits/stdc++.h>

using namespace std;
const int sigma_sz = 255;

class Solution {
 public:
  vector<string> generatePalindromes(string s) {
    int n = s.size();
    if (n == 1) return {s};
    vector<string> ans;
    vector<int> cnt(sigma_sz, 0);
    for (char c : s) ++cnt[c];

    char center = 0;
    for (int i=0; i<sigma_sz; ++i) if (cnt[i] & 1) center = i;

    int ocnt = 0;
    for (int d : cnt) if (d & 1) ++ocnt;
    if (ocnt > 1) return ans;

    for (int& d : cnt) d = d / 2;

    string path;
    multiset<char> ms;
    for (int i = 0; i < sigma_sz; ++i) {
      while (cnt[i]--) ms.insert(i);
    }
    dfs(ms, path, ans);

    
    for (string& s: ans) {
      const string t = string(s.rbegin(), s.rend());
      if (center) s.push_back(center);
      s += t;
    }
    return ans;
  }

  void dfs(multiset<char>& ms, string& path, vector<string>& ans) {
    if (ms.empty()) {
      ans.push_back(path);
      return;
    }
    vector<char> tmp(ms.begin(), ms.end());
    for (int i = 0; i < tmp.size(); ) {
      char v = tmp[i];
      path.push_back(v);
      ms.erase(ms.find(v));

      dfs(ms, path, ans);

      path.pop_back();
      ms.insert(v);
      while (i < tmp.size() && tmp[i] == v) ++i;
    }
  }
};
#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  Solution sol;
  string s; cin >> s;
  vector<string> ans = sol.generatePalindromes(s);
  for (const string& t: ans) cout << t << " ";
  cout << endl;
  return 0;
}
#endif
