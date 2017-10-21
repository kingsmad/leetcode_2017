#include <iostream>
#include <vector>
#include <string>

using namespace std;

int gcd(int x, int y) {
  bool neg = false;
  if (x < 0) { neg = !neg; x = -x;}
  if (y < 0) { neg = !neg; y = -y;}

  if (x > y) swap(x, y);
  if (x == 0) return y;
  if (x == 1) return 1;

  int z = y % x * (neg ? -1 : 1);
  return gcd(z, x);
}

bool IsFlag(char c ) { return c == '+' || c == '-';}

struct KSPoint {
  int x, y;
  void Add(const KSPoint& p) {
    int a = x * p.y + y * p.x;     
    int b = y * p.y;
    int c = gcd(a, b);
    a = a / c;
    b = b / c;
    x = a; y = b;
  }
  void Neg() {
    x = -x, y = -y;
  }
  KSPoint(int d1, int d2) : x(d1), y(d2) { }
};

class Solution {
 public:
  string fractionAddition(string expression) {
    KSPoint ans(0, 1);
    int n = expression.size();
    for (int i=0; i<n; ) {
      while(i < n && !isdigit(expression.at(i))) ++i;
      if (i == n) break;

      int x, y; 
      sscanf(expression.c_str() + i, "%d/%d", &x, &y);

      bool neg = false;
      if (i > 0 && expression.at(i-1) == '-') neg = true;
      x = neg ? -x : x;
     
      ans.Add(KSPoint(x, y));
      while(i < n && !IsFlag(expression.at(i))) ++i;      
    }

    char buf[100];
    sprintf(buf, "%d/%d", ans.x, ans.y);
    return string(buf);
  }
};
