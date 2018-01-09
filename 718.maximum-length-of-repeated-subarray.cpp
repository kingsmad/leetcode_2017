#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 1e3 + 10;
int dp[maxn][maxn];

class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    memset(dp, 0, sizeof(dp)); 
    for (int i=1; i<A.size()+1; ++i) for (int j=1; j<B.size()+1; ++j) {
      if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = 0;
    }

    int ans = 0;
    for (int i=1; i<A.size()+1; ++i)  for (int j=1; j<B.size()+1; ++j) {
      ans = max(ans, dp[i][j]);
    }

    return ans;
  }
};
