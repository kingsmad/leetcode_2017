#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<string> removeComments(vector<string>& source) {
    vector<string> result;
    bool comment = false;

    string s;
    for (auto& word : source) {
      int n = word.size();
      for (int i = 0; i < n; ++i) {
        char c = word[i];
        int j = i + 1;

        if (!comment && j < n && c == '/' && word[j] == '/') {
          break;
        } else if (!comment && j < n && c == '/' && word[j] == '*') {
          comment = true;
          i = j;
        } else if (comment && j < n && c == '*' && word[j] == '/') {
          comment = false;
          i = j;
        } else if (!comment) {
          s += c;
        }
      }

      if (!comment && !s.empty()) { result.emplace_back(s); s.clear();}
    }

    return result;
  }
};
