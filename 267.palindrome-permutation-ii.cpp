#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<string> generatePalindromes(string s) {
    int n = s.size();
    vector<string> ans;
    vector<int> cnt(26, 0);
    for (char c : s) ++cnt[c - 'a'];
    for (int d : cnt)
      if (d & 1) return ans;

    for (int& d : cnt) d = d / 2;

    string path;
  }
};
