#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int cnt = 0, len = flowerbed.size();
    for (int i=0; i<len; ++i) {
      if (flowerbed[i] == 1) continue;
      if (i-1 >= 0 && flowerbed[i-1] == 1) continue;
      if (i+1 < len && flowerbed[i+1] == 1) continue;
      flowerbed[i] = 1;
      ++cnt;
    }

    return cnt >= n;
  }
};
