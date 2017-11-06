#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n > 10) return 0;
    if (n == 1) return 10;
    if (n == 0) return 1;

    ll d1 = C(10, n), d2 = C(9, n-1);
    return d1 * f(n) - d2 * f(n-1) + countNumbersWithUniqueDigits(n-1);
  }

  ll C(int x, int y) {
    return f(x) / ((ll)f(x-y) * f(y));
  }

  ll f(int x) {
    if (x == 0) return 1;
    return (ll)x * f(x-1);
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char ** argv) {
  int n; scanf("%d", &n);
  Solution sol;
  
  int ans = sol.countNumbersWithUniqueDigits(n);

  printf("%d\n", ans);
  return 0;
}

#endif
