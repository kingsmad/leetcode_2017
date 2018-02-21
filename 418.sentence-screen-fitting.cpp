#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    int n = sentence.size(), num = 0, st = 0;
    vector<int> dp(n + 1, -1);
    while (rows--) {
      st = num % n;
      if (dp[st] == -1) {
        int cnt = 0, len = -1;
        while ((len = len + 1 + sentence[(st + cnt) % n].size()) <= cols) {
          ++cnt;
        }
        dp[st] = cnt;
      }
      num += dp[st];
    }

    return num / n;
  }
};
