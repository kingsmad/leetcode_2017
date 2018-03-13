#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int longestPalindrome(string s) {
    unordered_map<char, int> ms;      
    for (char c : s) ++ms[c];

    bool f = false;
    int ans = 0;
    for (auto& pr : ms) {
      if (pr.second & 1) {
        if (!f) { f = true; ans += pr.second;}
        else ans += pr.second - 1;
      }
      else ans += pr.second;
    }

    return ans;
  }
};
