// count the contribute of each index
#include <stack>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int maxn = 1e5 + 10;
int n;

int st[maxn][32];
void InitRmq(const vector<int>& nums) {
  int n = nums.size();
  for (int i=0; i<n; ++i) { st[i][0] = nums.at(i);}
  for (int j=1; (1<<j)<=n; ++j) {
    for (int i=0; i+(1<<j)<=n; ++i) {
      st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
    }
  }
}

int queryMax(int l, int r) {
  int k = 0;
  while(l + (1<<(k+1)) <= r) ++k;
  return max(st[l][k], st[r-(1<<k)][k]);
}

class Solution {
 public:
  int trap(vector<int>& height) {
    n = height.size();
    InitRmq(height);
    int ans = 0;
    for (int i=1; i+1<n; ++i) {
      int v = min(queryMax(0, i), queryMax(i+1, n)) - height.at(i);
      if (v > 0) ans += v;
    }
    return ans;
  }
};
