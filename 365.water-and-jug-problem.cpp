#include <iostream>
using namespace std;
class Solution {
 public:
  bool canMeasureWater(int x, int y, int z) {
    int g = gcd(x, y);
    return (x+y==z) || ((x+y>z) && (z%g == 0));
  }

  int gcd(int x, int y) {
    if (x > y) swap(x, y);
    if (x == 0) return y;
    return gcd(y%x, x);
  }
};
