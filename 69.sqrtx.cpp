#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
  int mySqrt(int x) {
    ll l = 0, r = x/2 + 2; 
    while(l < r) {
      ll md = (l + r) /2;
      double v = md * md;
      if (v < x) l = md + 1;
      else if (v > x) r = md;
      else return md;
    }
    return l-1;
  }
};
