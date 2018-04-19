#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    int n = g.size(); 
    multiset<int> msg(g.begin(), g.end());
    sort(s.begin(), s.end());
    for (int i=0; i<s.size(); ++i) {
      auto it = msg.lower_bound(s[i]);
      if (it != msg.end() && *it == s[i]) {
        msg.erase(it);
        continue;
      }
      if (it == msg.begin()) continue;
      --it;
      msg.erase(it);
    }
    return g.size() - msg.size();
  }
};
