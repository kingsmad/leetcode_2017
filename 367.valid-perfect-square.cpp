#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double eps = 1e-6;

class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num == 1) return true;
    double l = 0, r = num;
    while(r - l > eps) {
      double md = (l+r) / 2; 
      double v = md * md;
      if (v < num) l = md;
      else r = md;
    }

    int t = (int)(l+0.5);
    return abs(t - l) < eps;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  int num; scanf("%d", &num);
  Solution sol;
  
  bool ans = sol.isPerfectSquare(num);
  if (ans) printf("YES\n");
  else printf("NO\n");

  return 0;
}
#endif
