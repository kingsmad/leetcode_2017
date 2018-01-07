#include <vector>
#include <string>
#include <iostream>

using namespace std;
int row, col;

class Solution {
 public:
  int findLonelyPixel(vector<vector<char>>& picture) {
    row = picture.size();
    if (row == 0) return 0;
    col = picture.at(0).size();

    vector<int> rcnt(row, 0);
    vector<int> ccnt(col, 0);
    for (int i=0; i<row;++i) for(int j=0; j<col; ++j) {
      if (picture[i][j] == 'B') ++rcnt[i], ++ccnt[j];
    }

    int ans = 0;
    for (int i=0; i<row; ++i) for(int j=0; j<col; ++j) {
      if (picture[i][j] == 'B' && rcnt[i] == 1 && ccnt[j] == 1) ++ans;
    }

    return ans;
  }
};
