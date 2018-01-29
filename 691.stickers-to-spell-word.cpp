#include <vector>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
int n, m, dp[(1<<16)+10];

class Solution {
 public:
  int minStickers(vector<string>& stickers, string target) {
    n = stickers.size(), m = target.size();
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i=0; i<(1<<m); ++i) {
      if (dp[i] == -1) continue;

      for (int j=0; j<n; ++j) {
        const string& s = stickers.at(j);
        int st = i;   
        for (char c : s) {
          for (int z=0; z<m; ++z) {
            if (st & (1<<z)) continue;
            if (c == target[z]) {
              st = st | (1<<z);
              break;
            }
          }
        }
        if (dp[st] == -1 || dp[st] > dp[i] + 1) dp[st] = dp[i] + 1;
      }
    }

    return dp[(1<<m) - 1];
  }
};
