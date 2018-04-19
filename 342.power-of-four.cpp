#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int num) {
      while(1) {
        if (num == 1) return true;
        if (num == 0) return false;
        if (num % 4 > 0) return false;
        num /= 4;
      }
      return true;
    }
};
