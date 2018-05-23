#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
 public:
  bool judgeSquareSum(int c) {
    int p = 0, q = sqrt(c) + 1;
    while(p <= q) {
      ll v = p * p + q * q;
      if (v == c) return true;
      else if (v < c) ++p;
      else --q;
    }

    return false;
  }
};
