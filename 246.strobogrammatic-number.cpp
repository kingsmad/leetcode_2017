#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool isStrobogrammatic(string num) {
    int n = num.size();
    int p = 0, q = n - 1;
    while(p < q) {
      if (!check(num[p++]-'0', num[q--]-'0')) return false;
    }
    if (p == q) return num[p] == '1' || num[p] == '8' || num[p] == '0';
    return true;
  }

  bool check(char x, char y) {
    if (x == 8 && y == 8) return true; 
    if (x == 6 && y == 9) return true;
    if (x == 9 && y == 6) return true;
    if (x == 1 && y == 1) return true;
    if (x == 0 && y == 0) return true;
    // if (x == 2 && y == 2) return true;
    return false;
  }
};
