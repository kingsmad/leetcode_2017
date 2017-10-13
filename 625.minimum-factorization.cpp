#include <list>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;
using ll = long long;
const int maxn = 1e5 + 10;
int np[maxn];

class Solution {
 public:
  int smallestFactorization(int a) {
    if (a == 1) return 1;
    int n = sqrt(a);
    for (int i=2; i<=(n+1); ++i) {
      int p = i + i; 
      while(p <= n+1) { np[p] = 1; p += i;}
    }

    vector<int> ans;
    while(a % 9 == 0) { ans.push_back(9); a = a / 9;}
    while(a % 8 == 0) { ans.push_back(8); a = a / 8;}
    while(a % 6 == 0) { ans.push_back(6); a = a / 6;}
    while(a % 4 == 0) { ans.push_back(4); a = a / 4;}

    for (int i=2; i<=(n+1); ++i) {
      if (np[i]) continue;
      while(a % i == 0) { ans.push_back(i); a = a / i;}
    }

    if (a != 1) ans.push_back(a);

    for (int d : ans) if (d > 10) return 0;

    if (ans.size() > 10) return 0;
    sort(ans.begin(), ans.end());

    ll r = 0; 
    for (int d : ans) r = 10 * r + d;
    if ( r > INT_MAX) return 0;
    return r;
  }
};
