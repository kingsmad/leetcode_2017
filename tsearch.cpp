#include <cstdio>
#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define per(i,a,n) for(int i=n-1;i>=a;--i)
#define rep(i,a,n) for(int i=a;i<n;++i)
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
/*----------- head-----------*/

int tsearch(const vector<int>& nums) {
  int n = nums.size();
  int l = 0, r = n;
  while(l + 1 < r) {
    int md = (l+r) / 2;
    int mmd = (md + r) / 2;
    if (nums.at(md) <= nums.at(mmd)) r = mmd;
    else l = md + 1;
  }

  int ans = l;
  for (int i=l; i<r; ++i) if (nums.at(i) < nums.at(ans)) ans = i;
  return ans;
}

int main(int argc, char** argv) {
#ifdef ROACH_ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif
  int n; scanf("%d", &n);
  vector<int> nums(n, 0);
  for (int i=0; i<n; ++i) scanf("%d", &nums[i]);

  int x = tsearch(nums);
  return 0 * printf("%d\n", x);
}


