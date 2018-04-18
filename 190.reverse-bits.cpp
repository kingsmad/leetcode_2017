#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    int p = 0, q = 31;
    while(p < q) {
      bool d1 = (1<<p) & n;
      bool d2 = (1<<q) & n;
      if (d1 != d2) {
        n ^= (1<<p);
        n ^= (1<<q);
      }
      ++p, --q;
    }

    return n;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  uint32_t x = 43261596;
  Solution sol;
  uint32_t ans = sol.reverseBits(x);
  printf("%d\n", ans);
  return 0;
}
#endif
