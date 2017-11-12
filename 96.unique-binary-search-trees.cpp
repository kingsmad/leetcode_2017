#include < csting>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 10;
class Solution {
  int v[maxn];
 public:
  int numTrees(int n) {
    memset(v, -1, sizeof(v));
    return Calc(n);   
  }

  int Calc(int n) {
    if (n == 1 || n == 0) return 1;
    if (v[n] != -1) return v[n]; 

    int ans = 0;
    for (int i=0; i<n; ++i) {
      ans += Calc(i) * Calc(n-i-1); 
    }

    return v[n] = ans;
  }
};
