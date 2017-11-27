#include <vector>

using namespace std;
using ll = long long;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    return C(m+n-2, min(n-1, m-1));
  }

  ll C(ll x, ll y) {
    if (x == 0 || y == 0 || x == y) return 1;
    ll ans = 1;
    for (ll i=x; i>x-y; --i) ans *= i;
    return ans / factor(y);
  }

  ll factor(ll x) {
    ll ans = 1;
    for (int i=2; i<=x; ++i) ans *= i;
    return ans;
  }
};
