#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  string findLongestWord(string s, vector<string>& d) {
    int ans = 0;
    string ms = "";

    for (const string& ts : d) if (Check(s, ts)) {
      if (ts.size() > ans || (ts.size() == ans && ts < ms)) {
        ans = ts.size();
        ms = ts;
      }
    }
    return ms;
  }

  bool Check(const string& s, const string& ts) {
    int p = s.size() - 1;
    for (int i=ts.size()-1; i>=0; --i) {
      while(p >= 0 && s[p] != ts[i]) --p;
      if (p == -1) return false;
      --p;
    }
    return true;
  }
};
