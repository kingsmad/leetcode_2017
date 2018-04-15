#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string convertToTitle(int n) {
    string ans; 
    while(n>0) {
      ans.push_back('A' + (n-1)%26);
      n = (n-1) / 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
