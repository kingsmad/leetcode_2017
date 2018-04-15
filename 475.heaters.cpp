#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int ans = 0;
    for (int d : houses) {
      int p = lower_bound(heaters.begin(), heaters.end(), d) - heaters.begin();
      if (p == heaters.size()) p = heaters.size() - 1;
      if (p > 0) {
        if (d - heaters[p-1] < heaters[p] - d) p = p - 1;
      }
      ans = max(ans, abs(heaters[p] - d));
    }

    return ans;
  }
};
