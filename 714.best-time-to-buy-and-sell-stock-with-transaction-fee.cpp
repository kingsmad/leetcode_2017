#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    if (n == 0) return 0;
    
    int buy = -prices.at(0);
    int sell = 0;

    for (int i=1; i<n; ++i) {
      sell = max(sell, buy + prices.at(i) - fee);
      buy = max(buy, sell - prices.at(i));
    }

    return sell;
  }
};
