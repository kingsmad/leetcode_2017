#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
 public:
  int largestPalindrome(int n) {
    if (n == 1) return 9;
    int ceil = pow(10, n) - 1;
    int floor = pow(10, n-1);
    for (int i=ceil; i>=floor; --i) {
      ll v = calc(i); 
      for (ll j=ceil; j*j>=v; --j) {
        if (v % j == 0 && v / j <= ceil) return v % 1337;
      }
    }

    return -1;
  }

  ll calc(int n) {
    string s = to_string(n);
    string t  = s;
    reverse(t.begin(), t.end());
    return stol(s + t);
  }
};
