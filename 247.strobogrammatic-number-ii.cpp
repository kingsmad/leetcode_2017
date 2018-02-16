#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<string> findStrobogrammatic(int n) {
    vector<string> ans = {""};
    if (n & 1) ans = {"0", "1", "8"};

    vector<string> tmp;
    for (int i = n % 2; i < n; i += 2) {
      tmp.clear();
      for (const string& s : ans) {
        if (i + 2 < n) tmp.emplace_back("0" + s + "0");
        tmp.emplace_back("1" + s + "1");
        tmp.emplace_back("6" + s + "9");
        tmp.emplace_back("9" + s + "6");
        tmp.emplace_back("8" + s + "8");
      }
      ans = tmp;
    }

    return ans;
  }
};
