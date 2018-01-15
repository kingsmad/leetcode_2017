#include <climits>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5 + 10;
int n, dp[maxn], dp1[maxn];

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    n = nums.size();
    dp1[0] = dp[0] = nums.at(0);
    
    for (int i=1; i<n; ++i) {
      vector<int> vc({nums.at(i), dp[i-1] * nums.at(i), dp1[i-1] * nums.at(i)});
      sort(vc.begin(), vc.end());
      dp[i] = vc.front();
      dp1[i] = vc.back();
    }

    int ans = INT_MIN;
    for (int i=0; i<n; ++i) ans = max(ans, dp1[i]);
    return ans;
  }
};
