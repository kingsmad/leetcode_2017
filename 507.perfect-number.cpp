#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool checkPerfectNumber(int num) {
    if (num == 1) return false;
    int sum = 1;
    int cap = sqrt(num);
    for (int i=2; i<=cap; ++i) {
      if (num % i == 0) sum += num / i + i;
    }
     printf("%d\n", sum);
    return sum == num;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  int num; scanf("%d", &num);
  Solution sol;
  bool ok = sol.checkPerfectNumber(num);
  if (ok) printf("YES\n");
  else printf("NO\n");
  return 0;
}

#endif
