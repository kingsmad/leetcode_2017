#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<string> ans;
 public:
  vector<string> readBinaryWatch(int num) {
    ans.clear(); 
    dfs(0, 0, num); 
  
    return ans;
  }

  void dfs(int state, int p, int rem) {
    if (rem == 0) {
      int h = 0, m = 0;
      for (int i = 0; i < 10; ++i) {
        if (state & (1 << i)) {
          if (i < 4)
            h += (1 << i);
          else
            m += (1 << (i-4));
        }
      }
      if (h < 12 && m < 60) {
        char b[20];
        sprintf(b, "%d:%02d", h, m);
        ans.emplace_back(b);
      }
      return;
    }
    if (p == 10) return;

    dfs(state | (1<<p), p+1, rem-1);
    dfs(state, p+1, rem);
  }
};
