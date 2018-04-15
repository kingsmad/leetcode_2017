#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n = words.size();
    vector<string> ans;
    for (int i=0; i<n; ) {
      int q = i + 1, tot = words[i].size();
      while(q < n && tot+1+words[q].size() <= maxWidth) tot = tot + 1 + words[q++].size();
      ans.push_back(ksparse(i, q, words, maxWidth));
      i = q; 
    }
    return ans;
  }

  const string ksparse(int st, int q, const vector<string>& words, int cap) {
    string ans;
    if (st + 1 == q) {
      ans += words[st]; 
      ans.resize(cap, ' ');
      return ans;
    }
    int clen = 0;
    for (int i=st; i<q; ++i) clen += words[i].size();
    int tlen = (cap-clen) / (q-st-1);
    int res = cap - clen - tlen * (q-st-1);

    if (q == words.size()) {
      tlen = 1;
      res = 0;
    }
    for (int i=st; i<q; ++i) {
      ans += words[i];
      if (i + 1 == q) break;
      ans += string(tlen, ' ');
      if (res) { ans += ' '; --res;}
    }
    ans.resize(cap, ' ');
    return ans;
  }
};
