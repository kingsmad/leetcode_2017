#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string, int>> mq;
    mq.push({beginWord, 0});
    int n = wordList.size();
    vector<bool> done(n, false);
    while(mq.size()) {
      const string s = mq.front().first;
      int lev = mq.front().second;
      mq.pop();

      if (s == endWord) return lev + 1;

      for (int i=0; i<n; ++i) {
        if (done[i]) continue;
        if (check(s, wordList.at(i))) {
          mq.push({wordList.at(i), lev+1});
          done[i] = true;
        }
      }
    }

    return 0;
  }

  bool check(const string& s1, const string& s2) {
    int n = s1.size();
    int cnt = 0;
    for (int i=0; i<n; ++i) if (s1.at(i) != s2.at(i) && ++cnt > 1) return false;
    return true;
  }
};
