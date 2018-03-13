#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int repeatedStringMatch(string A, string B) {
    vector<int> fail(B.size()+1);
    getFail(B, fail);

    int cnt = 1;
    string t = A;

    while(1) {
      if (kmp(B, t, fail) > 0) return cnt; 
      if (t.size() > 2 * B.size()) break;
      t += A;
      ++cnt;
    }
    
    return -1;
  }

  void getFail(const string& p, vector<int>& fail) {
    int n = p.size();

    int i, j = -1;
    for (i = 0; i<n; ++i, ++j) {
      fail[i] = (~j && p[i] == p[j]) ? fail[j] : j;
      while (~j && p[i] != p[j]) j = fail[j];
    }
    fail[i] = j;
  }

  int kmp(const string& p, const string& t, const vector<int>& fail) {
    int i, j = 0, ans = 0;
    int pn = p.size(), tn = t.size();
    for (i = 0; i < tn; ++i) {
      while (~j && t[i] != p[j]) j = fail[j];
      if (++j == pn) {
        ++ans;
        j = fail[j];
      }
    }

    return ans;
  }
};
