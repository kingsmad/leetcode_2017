#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool canPermutePalindrome(string s) {
    int cnt =0;
    unordered_map<char, int> ms;
    for (char c : s) { ++ms[c]; }
    for (auto& pr : ms) if (pr.second & 1) ++cnt;

    return cnt < 2;
  }
};
