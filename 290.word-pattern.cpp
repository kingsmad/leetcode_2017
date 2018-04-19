#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<string> split(string str) {
    vector<string> strs;
    int n = str.size();
    for (int i = 0; i < n;) {
      int q = i + 1;
      while (q < n && str[q] != ' ') ++q;
      strs.emplace_back(str.substr(i, q-i));
      i = q + 1;
    }
    return strs;
  }

  bool wordPattern(string pattern, string str) {
    unordered_map<char, int> c2sid;
    unordered_map<string, int> str2sid;
    int sz = 0;

    vector<string> strs = split(str);

    // check number
    if (strs.size() != pattern.size()) return false;
    int n = strs.size();

    // check pattern
    for (int i = 0; i < n; ++i) {
      bool f1 = c2sid.count(pattern[i]), f2 = str2sid.count(strs[i]);
      if (f1 && f2 && c2sid[pattern[i]] != str2sid[strs[i]]) return false;
      if (!f1 && !f2) c2sid[pattern[i]] = str2sid[strs[i]] = sz++;
      else if (!f1 || !f2) return false;
    }
    return true;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char** argv) {
  const string pattern = "abba";
  const string str = "dog cat cat dog";
  Solution sol;
  bool ans = sol.wordPattern(pattern, str);
  if (ans) printf("YES\n");
  else printf("NO\n");
}
#endif
