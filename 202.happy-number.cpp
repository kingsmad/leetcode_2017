#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> ms;
    while (1) {
      int tot = 0, x = n;
      while (x) {
        tot += (x % 10) * (x % 10);
        x /= 10;
      }
      if (tot == 1) return true;
      if (ms.count(tot) > 0) return false;
      ms.insert(tot);
      n = tot;
    }
    return false;
  }
};
