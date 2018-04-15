#include <bits/stdc++.h>
using namespace std;
class StringIterator {
 queue<pair<char, int>> mq;
 public:
  StringIterator(string compressedString) {
    mq = queue<pair<char, int>>();
    int n = compressedString.size();
    for (int i = 0; i < n;) {
      char c = compressedString[i];
      int q = i + 1;
      int d = 0;
      while (q < n && isdigit(compressedString[q]))
        d = 10 * d + compressedString[q++] - '0';
      mq.push({c, d});
      i = q;
    }
  }

  char next() {
    if (mq.empty()) return ' '; 
    pair<char, int>& pr = mq.front();
    char ans = pr.first;
    --pr.second;
    if (pr.second == 0) mq.pop();
    return ans;
  }

  bool hasNext() { return mq.size(); }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
