#include <iostream>
#include <math.h>

using namespace std;
using ll = long long;

class Solution {
 public:
  int kthGrammar(int N, int K) {
    if (N == 1) return 0; 
    
    ll p = pow(2, N-1);
    if (K <= p/2) return kthGrammar(N-1, K);
    else return 1 - kthGrammar(N-1, K-p/2);
  }
  
};
