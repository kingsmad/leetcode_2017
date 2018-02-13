#include <bits/stdc++.h>

using namespace std;
int ttx, tty;
bool ok = false;
int gcd(int x, int y) {
  if (x == ttx && y == tty) { ok = true;}
  if (x < y) return gcd(y, x);
  if (y == 0) return x;
  return gcd(y, x%y);
}

class Solution {
 public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    ok = false;
    ttx = sx, tty = sy;

    gcd(tx, ty);
    return ok;
  }
};
