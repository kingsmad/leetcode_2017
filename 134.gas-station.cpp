#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    for (int i=0; i<n; ) {
      int p = i, tot = gas[p];
      int cnt = n;
      while(cnt > 0) {
        if (tot < cost[p]) break;
        tot -= cost[p];
        p = (p+1) % n;
        tot += gas[p];
        --cnt;
      }
      if (cnt == 0) return i;
      if (p < i) return -1;
      i = p + 1;
    }
    return -1;
  }
};
