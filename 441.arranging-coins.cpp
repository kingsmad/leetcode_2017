#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
 public:
  int arrangeCoins(int n) {
    int step = 1;
    while (n >= step) { n -= step++; }
    return step - 1;
  }
};
