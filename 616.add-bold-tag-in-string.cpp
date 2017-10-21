#include <cstring>
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
};
