#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

class Solution {
 public:
  int countCornerRectangles(vector<vector<int>>& grid) {
    vector<int> buf;
    int row = grid.size();
    if (row == 0) return 0;
    int col = grid.at(0).size();


    int ans = 0;
    for (int i=0; i<row; ++i) {
      for (int j=i+1; j<row; ++j) {
        int v = 0;
        for (int z=0; z<col; ++z) {
          if (grid[i][z] == grid[j][z] && grid[i][z]==1) ++v;
        }
        ans += v * (v-1) / 2;
      }
    }

    return ans;
  }

};
