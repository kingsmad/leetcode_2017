#include <cstring>
#include <set>
#include <vector>
#include <string>

using namespace std;

const int maxn = 1e4 + 10;
bool dp[maxn];

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    memset(dp, 0, sizeof(dp)); 
    int n = s.size();
    set<string> ms(wordDict.begin(), wordDict.end());
    dp[0] = true;
    for (int i=1; i<=n; ++i) {
      for (int j=0; j<i; ++j) {
        if (dp[j] && ms.count(s.substr(j, i-j))) dp[i] = true;
      }
    }

    return dp[n];
  }
};
