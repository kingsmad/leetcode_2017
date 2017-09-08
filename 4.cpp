/*************************************************************************
  > In god we trust
  > File Name: 4.cpp
 ************************************************************************/
const bool debug = false;
#include <cstdio>
#include <iostream>
#include <cmath>
#include <stack>
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

class Solution {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int k = (nums1.size() + nums2.size()) / 2;
      if ((nums1.size() + nums2.size()) & 1) return FindKth(k, nums1, nums2);
      else return (FindKth(k, nums1, nums2) + FindKth(k-1, nums1, nums2)) / 2.0;
    }
    int FindKth(int k, vector<int>& v1, vector<int>& v2) {    
      int l = 0, r = v1.size();
      while(l < r) {
        int md = (l+r)/2;
        int ps = GetPos(v1[md], v1, v2);
        if (ps == k) return v1[md];
        else if (ps < k) l = md + 1;
        else r = md;
      }

      l = 0, r = v2.size();
      while(l < r) {
        int md = (l+r)/2;
        int ps = GetPos(v2[md], v1, v2);
        if (ps == k) return v2[md];
        else if (ps < k) l = md + 1;
        else r = md;
      }
    }

    int GetPos(int p, vector<int>& v1, vector<int>& v2) {
      return (lower_bound(v1.begin(), v1.end(), p) - v1.begin())
        + (lower_bound(v2.begin(), v2.end(), p) - v2.begin());
    }
};

int main() {
#ifdef ROACH_ONLINE_JUDGE
  freopen("4.txt", "r", stdin);
#endif
  vector<int> v1, v2;
  Solution sol;
  int n1, n2; 

  scanf("%d", &n1); 
  rep(i, 0, n1) {
    int d; scanf("%d", &d);
    v1.pb(d);
  }
  scanf("%d", &n2);
  rep(i, 0, n2) {
    int d; scanf("%d", &d);
    v2.pb(d);
  }
  int ans = sol.findMedianSortedArrays(v1, v2);
  return 0 * printf("%d\n", ans);
}
