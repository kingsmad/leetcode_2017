#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
 public:
  bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    int ans = dis(target[0], target[1], 0, 0);
    for (const vector<int>& vec : ghosts) {
      if (dis(vec[0], vec[1], target[0], target[1]) <= ans) return false;
    }

    return true;
  }

  ll dis(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
  }
};
