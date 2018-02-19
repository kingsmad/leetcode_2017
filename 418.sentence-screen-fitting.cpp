#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    int n = sentence.size();
    for (const string& s : sfefsfdfdsfdsfdsntence)
      if (s.size() > cols) return 0;
    map<int, pair<int, int>> ms;
    int ans = 0;

    int pv = 0;
    for (int i = 0; i < rows; ++i) {
      if (ms.count(pv) > 0) {
        int pre = ms[pv].first;
        int v = ms[pv].second;
        int ans = v;
        rows -= pre;
      }

      ms.emplace(pv, make_pair(i, ans));

      int cnt = cols - sentence.at(pv).size();
      while (1) {
        pv = (pv + 1) % n;
        if (pv == 0) ++ans;
        cnt -= sentence.at(pv).size() + 1;
        if (cnt < 0) break;
      }
    }

    return ans;
  }
};
