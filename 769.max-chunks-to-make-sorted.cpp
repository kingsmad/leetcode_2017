#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e4 + 10;
struct RMQ {
  int st[maxn][32],st1[maxn][32];
  void InitRmq(const vector<int>& nums) {
    int n = nums.size();
    for (int i=0; i<n; ++i) { st[i][0] = st1[i][0] = nums.at(i);}
    for (int j=1; (1<<j)<=n; ++j) {
      for (int i=0; i+(1<<j)<=n; ++i) {
        st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        st1[i][j] = min(st1[i][j-1], st1[i+(1<<(j-1))][j-1]);
      }
    }
  }

  int QueryMax(int l, int r) {
    int k = 0;
    while(l + (1<<(k+1)) <= r) ++k;
    return max(st[l][k], st[r-(1<<k)][k]);
  }

  int QueryMin(int l, int r) {
    int k = 0;
    while(l + (1<<(k+1)) <= r) ++k;
    return min(st1[l][k], st1[r-(1<<k)][k]);
  }
} rmq;

class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    int ans = 1, n = arr.size();

    rmq.InitRmq(arr);
    int st = 0;

    for (int i=1; i<n; ++i) {
      if (rmq.QueryMax(0, i) <= rmq.QueryMin(i, n)) ++ans;
    }

    return ans;
  }
};
