#include <bitset>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 1e8 + 10;
int n = -1;
bitset<maxn> dp;
bitset<maxn> flag;

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    n = A.size();
    flag.reset();
    dp.reset();

    int cnt = 0;
    for (int i=0; i<n; ++i) for (int j=i+2; j<n; ++j) {
      if (Calc(i, j, A)) ++cnt;
    }

    return cnt;
  }

  int Calc(int p, int q, const vector<int>& A) {
    if (p == q) return 1;

    int x = Sid(p, q, n);
    if (flag[x]) return dp[x];

    if ((A.at(q) - A.at(q-1) == A.at(p+1) - A.at(p)) && Calc(p, q-1, A) ) {
      dp.set(x);
      flag.set(x);
      return 1;
    } 

    dp.set(x, 0);
    flag.set(x);
    return 0;
  }

  int Sid(int p, int q, int n) {
    return p * (n+1) + q;
  }
};
