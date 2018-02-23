#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int lengthOfLongestSubstringTwoDistinct(string s) {
    int n = s.size(); 
    unordered_map<char, int> ms;
    
    int l = 0, r = 0, ans = 0;
    while(r < n) {
      char c = s[r];
      ++ms[c];
      while(ms.size() > 2) {
        if (--ms[s.at(l)] == 0) ms.erase(s.at(l));
        ++l;
      }
      ++r;
      ans = max(ans, r - l);
    }

    return ans;
  }
};
