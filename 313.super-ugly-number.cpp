#include <climits>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], sz;

class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    int len = primes.size();
    a[0] = 1; sz = 1;

    vector<int> sids(len, 0);
    for(int i=0; i<sids.size(); ++i) sids[i] = 0;
    
    while( sz <= n ) {
      int v = INT_MAX;
      for (int i=0; i<len; ++i) {
        v = min(v, primes.at(i) * a[sids[i]]); 
      }
      a[sz++] = v;
      
      for (int i=0; i<len; ++i) {
        while(a[sids[i]] * primes[i] <= a[sz-1]) ++sids[i];
      }
    }

    return a[n-1];
  }
};
