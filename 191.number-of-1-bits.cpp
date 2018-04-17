#include <bits/stdc++.h>
using namespace std;
inline int lowbit(int x) { return x & (-x);}
class Solution {
public:
    int hammingWeight(uint32_t n) {
      int cnt  = 0; 
      while(n) {
        n -= lowbit(n);
        ++cnt;
      }
      return cnt;
    }
};
