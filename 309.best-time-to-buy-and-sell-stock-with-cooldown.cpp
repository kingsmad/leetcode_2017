#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<int> on_stock(n + 1, 0);
    vector<int> off_stock(n + 1, 0);

    on_stock[1] = -prices[0];
    for (int i = 2; i <= n; ++i) {
      on_stock[i] = max(on_stock[i-1], off_stock[i - 2] - prices[i - 1]);
      off_stock[i] = max(off_stock[i - 1], on_stock[i - 1] + prices[i - 1]);
    }

    return off_stock[n];
  }
};
