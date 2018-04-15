#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<int> mi(n, INT_MAX);
    mi[0] = prices[0];
    for (int i=1; i<n; ++i) mi[i] = min(mi[i-1], prices[i]);
    int ans = 0;
    for (int i=1; i<n; ++i) {
      ans = max(ans, prices[i] - mi[i-1]); 
    }
    return ans;
  }
};
