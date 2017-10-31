#include <iostream>
#include <vector>


// 35732 = ((((3 * 10 + 5) * 10 + 7) * 10 + 3) * 10 + 2)
// a^35732 = ..... 
// think about it why should we must iterate the array from the last element.

using namespace std;
using ll = long long;

const ll mod = 1337;

ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  for(; b; b >>= 1){
    if(b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}

class Solution {
 public:
  int superPow(int a, vector<int>& b) {
    int n = b.size();
    a %= mod;

    ll res = 1;
    for (int i=n-1; i>=0; --i) {
      int d = b.at(i);
      res = res * powmod(a, d) % mod;    
      a = powmod(a, 10) % mod;
    }

    return res;
  }
};
