#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int countPrimes(int n) {
    vector<bool> npr(n+1, 0);
    int cap = sqrt(n) + 2;
    for (int i=2; i<cap; ++i) {
      if (npr[i]) continue;
      for (int j=i+i; j<=n; j+=i) npr[j] = true;
    }

    int ans = 0;
    for (int i=2; i<n; ++i) {
      ans += !npr[i];
    }
    return ans;
  }
};
