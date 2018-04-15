#include <bits/stdc++.h>

using namespace std;
using ll = long long;
inline int lowbit(int x) { return x & (-x);}

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n == 0 || n == INT_MIN) return false;
    return n - lowbit(n) == 0; 
  }
};
