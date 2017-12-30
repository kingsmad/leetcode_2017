// Mark
#include <climits>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

const int maxn = 1e4 + 10;

class Solution {
  int st[maxn][32], st1[maxn][32];
 public:
  bool verifyPreorder(vector<int>& preorder) {
    int n = preorder.size();
    if (n == 0) return true;
    InitRmq(preorder);

    return Check(0, n, preorder); 
  }

  bool Check(int l, int r, const vector<int>& num) {
    if (l == r) return true;

    int p = l+1, q = r, pv = num.at(l);
    while(p < q) {
      int md = (p+q) / 2;
      if (num.at(md) < pv) p = md + 1;
      else if (num.at(md) > pv) q = md;
      else return false;
    }

    int x = p;

#ifdef ROACH_ONLINE_JUDGE
     printf("Root of (%d, %d) is %d\n", l, r, x);
#endif

    if (x > l+1 && queryMax(l+1, x) >= pv) return false;
    if (r > x && queryMin(x, r) <= pv) return false;
  
    return Check(l+1, x, num) && Check(x, r, num); 
  }

  void InitRmq(const vector<int>& nums) {
    int n = nums.size();
    for (int i=0; i<n; ++i) { st[i][0] = st1[i][0] = nums.at(i); }
    for (int j=1; (1<<j)<=n; ++j) {
      for (int i=0; i+(1<<j)<=n; ++i) {
        st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        st1[i][j] = min(st1[i][j-1], st1[i+(1<<(j-1))][j-1]);
      }
    }
  }

  int queryMax(int l, int r) {
    int k = 0;
    while(l + (1<<(k+1)) <= r) ++k;
    return max(st[l][k], st[r-(1<<k)][k]);
  }

  int queryMin(int l, int r) {
    int k = 0;
    while(l + (1<<(k+1)) <= r) ++k;
    return min(st1[l][k], st1[r-(1<<k)][k]);
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  int n; scanf("%d",&n);
  vector<int> preorder; 
  for (int i=0; i<n; ++i) { int d; scanf("%d", &d); preorder.push_back(d);}

  Solution sol;
  bool ok = sol.verifyPreorder(preorder);
  if (ok) printf("OK\n");
  else printf("NO\n");

  return 0;
}
#endif
