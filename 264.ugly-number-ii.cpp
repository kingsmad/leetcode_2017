#include <assert.h>
#include <set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

const int num[4] = { 2, 3, 4, 5};
const int maxn = 1e5 + 10;
int a[maxn], sz;

class Solution {
 public:
  int nthUglyNumber(int n) {
    a[0] = 1, a[1] = 2, a[2] = 3, a[3] = 4, a[4] = 5; 
    sz = 5;

    // smallest index that if multiply (2, 3, 5) then will larger;
    int p = 2, q = 1, t = 1;

    while(sz <= n) {
      int u = min(a[p] * 2, a[q] * 3);
      u = min(u, a[t] * 5);
      a[sz++] = u;
     
      while(p < sz && a[p] * 2 <= a[sz-1]) ++p;
      while(q < sz && a[q] * 3 <= a[sz-1]) ++q;
      while(t < sz && a[t] * 5 <= a[sz-1]) ++t;
    }

    return a[n-1];
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  int n; scanf("%d", &n);
  Solution sol;
  int ans = sol.nthUglyNumber(n);
  printf("%d\n", ans);
  return 0;
}
#endif
