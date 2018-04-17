#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int ans = 0, n = prices.size();
    for (int i=0; i+1<n; ++i) {
      ans += max(0, prices[i+1] - prices[i]);
    }
    return ans;
  }
};
