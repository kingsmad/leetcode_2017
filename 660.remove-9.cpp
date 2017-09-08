#include <iostream>
#include <math.h>

using namespace std;

using ll = long long;
class Solution {
  ll dp[11];
  bool done = false;
  void Init() {
    if (done) return;
    done = true;

    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    for (int i = 2; i < 11; ++i) { dp[i] = 9 * dp[i - 1] + pow(10, i - 1); }
  }

 public:
  ll calc(int n) {
    if (n < 10) return n == 9;
    ll c = n, cnt=0; while(c>=10) { c=c/10; ++cnt;}
    ll res = c * dp[cnt];
    if (c == 9) res += n - c * pow(10, cnt) + 1;
    else res += calc(n - c * pow(10, cnt));
    return res;
  }

  ll f(int n) {
    return n - calc(n);
  }

  int newInteger(int n) { 
    Init(); 
    ll l = 0, r = INT_MAX;
    while(l < r) {
      int md = (l+r)/2;
      ll res = f(md);
      if (res < n) l = md + 1;
      else r = md;
    }

    return l;
  }
};

/*int main(int argc, char** argv) {
  Solution sol;  
  int n; scanf("%d", &n);
  int res = sol.newInteger(n);

  printf("%d\n", res);

  return 0;
}*/
