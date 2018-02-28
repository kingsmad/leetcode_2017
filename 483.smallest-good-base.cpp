#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
 public:
  string smallestGoodBase(string n) {
    ll num = stol(n);
    for (int i = log(num + 1) / log(2); i >= 2; --i) {
      ll l = 2, r = pow(num, 1.0 / (i - 1)) + 1;
      while (l < r) {
        ll md = l + (r - l) / 2;

        ll sum = 0;
        for (int j = 0; j < i; ++j) { sum = sum * md + 1; if (sum > num) break;}

        if (sum == num) return to_string(md);
        else if (sum < num) l = md + 1;
        else r = md;
      }
    }
    return to_string(num - 1);
  }
};
