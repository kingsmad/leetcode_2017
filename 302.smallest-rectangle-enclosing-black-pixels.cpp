#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minArea(vector<vector<char>>& image, int x, int y) {
    int left = y, right = y, up = x, down = x;
    for (int i = 0; i < image.size(); ++i) {
      for (int j = 0; j < image[i].size(); ++j) {
        if (image[i][j] == '1') {
          left = min(left, j);
          right = max(right, j);
          up = min(up, i);
          down = max(down, i);
        }
      }
    }
    return (right - left + 1) * (down - up + 1);
  }
};
