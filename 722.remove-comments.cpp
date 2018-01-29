#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define per(i, a, n) for (int i = n - 1; i >= a; --i)
#define rep(i, a, n) for (int i = a; i < n; ++i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
#define lc(o) (o << 1)
#define rc(o) (o << 1 | 1)
ll powmod(ll a, ll b, ll MOD) {
  ll res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
/*----------- head-----------*/

class Solution {
public:
  vector<string> removeComments(vector<string> &source) {
    
  }
};
