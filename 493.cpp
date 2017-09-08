/*************************************************************************
  > In god we trust
  > File Name: 493.cpp
 ************************************************************************/
const bool debug = false;
#include <cstdio>
#include <iostream>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <queue>
#include <climits>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <stdarg.h>
using namespace std;
#define per(i,a,n) for(int i=n-1;i>=a;--i)
#define rep(i,a,n) for(int i=a;i<n;++i)
#define erep(i,a,n) for(int i=a;i<=n;++i)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
#define lc(o) (o<<1)
#define rc(o) (o<<1|1)
ll powmod(ll a,ll b, ll MOD) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
void buginfo(const char* f, ...) {if(!debug)return;va_list al; va_start(al, f);vprintf(f, al);va_end(al);}
/*------------------ head-------------------*/
inline int lowbit(int x) { return x & (-x);}
typedef long long ll;
unordered_map<ll, int> val2id;
int sid = 1;
const int maxn = 1e5 + 10;

class Solution {
  struct FenWickTree {
    int n;
    int c[maxn];
    void init (int nt) { 
      n = nt;
      memset(c, 0, (n+1) * sizeof(int));
    }

    void update(int p, int v) {
      for (int i=p; i<=n; i+=lowbit(i)) c[i] += v;
    }

    int query(int x) {
      int res = 0;
      for (int i=x; i>0; i-=lowbit(i)) res += c[i];
      return res;
    }

    int Calc(int x) {
      return query(n) - query(x);
    }
  } ftree;
  public:
  int reversePairs(vector<int>& nums) {
    val2id.clear();
    vector<int> buf;
    for(int d: nums) { buf.push_back(d); buf.push_back(2*d);}
    sort(buf.begin(), buf.end());
    for(int d: buf) Val2Id(d);

    ftree.init(2 * nums.size()+1);
    int ans = 0;
    for(int d: nums) {
      ans += ftree.Calc(1ll*Val2Id(d)*2);
      ftree.update(Val2Id(d), 1);
    }
    return ans;
  }

  int Val2Id(int x) {
    if (val2id.count(x) > 0) return val2id.at(x);
    val2id.emplace(x, sid);
    return sid++;
  }
};

int main() {
#ifdef ROACH_ONLINE_JUDGE
  freopen("493.txt", "r", stdin);
#endif
  int n; scanf("%d", &n);
  vector<int> nums(n, 0);
  rep(i, 0, n) scanf("%d", &nums[i]);
  Solution sol;
  int ans = sol.reversePairs(nums);
  return 0 * printf("%d\n", ans);
}
