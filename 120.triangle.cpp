#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxm = 1e3 + 10;
int dp[2][maxm];

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int cur = (n-1)%2;
    for (int i=0; i<triangle.at(n-1).size(); ++i) {
      dp[cur][i] = triangle.at(n-1).at(i);  
    }

    for (int i=n-2; i>=0; --i) {
      const vector<int>& vc = triangle.at(i);
      for (int j=0; j<vc.size(); ++j) {
        dp[i%2][j] = min(dp[(i+1)%2][j], dp[(i+1)%2][j+1]) + vc[j];
      }
    }

    return dp[0][0];
  }
};
