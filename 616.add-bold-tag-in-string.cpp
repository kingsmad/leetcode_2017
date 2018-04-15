/*#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string addBoldTag(string s, vector<string>& dict) {
    int n = s.size();
    vector<bool> v(n, false);
    for (const string& ss : dict) {
      for (int i = 0; i < n; ++i) {
        if (s.substr(i, ss.size()) == ss) {
          for (int j = 0; j < ss.size(); ++j) { v[i + j] = true; }
        }
      }
    }

    string ans = "";
    string sub = "";
    bool f = false;
    for (int i = 0; i < n; ++i) {
      if (v.at(i) != f && !sub.empty()) {
        if (f) ans += "<b>";
        ans += sub;
        if (f) ans += "</b>";
        sub.clear();
      }

      sub.push_back(s.at(i));
      f = v.at(i);
    }

    if (!sub.empty()) {
      if (f) ans += "<b>";
      ans += sub;
      if (f) ans += "</b>";
      sub.clear();
    }

    return ans;
  }
}; */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int fail[maxn];

void getFail(const string& p, int* fail) {
  int i, j = -1;
  int n = p.size();
  for (i = 0; i < n; ++i, ++j) {
    fail[i] = (~j && p[i] == p[j]) ? fail[j] : j;
    while (~j && p[i] != p[j]) j = fail[j];
  }
  fail[i] = j;
}

vector<int> kmp(const string& p, const string& t, int* fail) {
  int i, j = 0;
  int pn = p.size(), tn = t.size();
  vector<int> ans;
  getFail(p, fail);

  for (i = 0; i < tn; ++i) {
    while (~j && t[i] != p[j]) j = fail[j];
    if (++j == pn) {
      ans.push_back(i - pn + 1);
      j = fail[j];
    }
  }

  return ans;
}

class Solution {
 public:
  string addBoldTag(string s, vector<string>& dict) {
    int n = s.size();
    vector<bool> b(n, false);
    for (const string& p : dict) {
      vector<int> vp = kmp(p, s, fail);
      for (int st : vp) {
        for (int i = st; i < st + p.size(); ++i) { b[i] = true; }
      }
    }

    string ans;
    for (int i = 0; i < s.size();) {
      if (!b[i]) {
        ans += s[i++];
        continue;
      }
      int q = i + 1;
      while (q < n && b[q]) ++q;
      ans += "<b>";
      ans += s.substr(i, q - i);
      ans += "</b>";
      i = q;
    }

    return ans;
  }
};

int main(int ,char**) {
  string s = "abcxyz123";
  vector<string> dict = {"abc", "123"};
  Solution sol;
  string ans = sol.addBoldTag(s, dict);
  cout << ans << endl;
}
