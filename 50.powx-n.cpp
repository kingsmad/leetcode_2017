#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;

class Solution {
 public:
  double myPow(double x, int n) {
    ll b = n;
    bool neg = (n < 0);
    if (neg) b = -b;

    double res = 1.0;
    for (; b; b>>=1) {
      if (b & 1) res = res * x;
      x = x * x;
    }

    return neg ? 1.0 / res : res;
  }
};

/*ll powmod(ll a, ll b, ll MOD) {
  ll res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}*/

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  Solution sol;
  double x, n; cin >> x >> n;
  double ans = sol.myPow(x, n);
  cout << ans << endl;

  return 0;
}
#endif
