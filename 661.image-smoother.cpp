#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    if (M.empty()) return M;
    int row = M.size(), col = M.at(0).size();
    vector<vector<int>> ans(row, vector<int>(col, 0));
    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
      int v = 0, cnt = 0;
      for (int x=0; x<3; ++x) for (int y=0; y<3; ++y) {
        int nx = x + i - 1, ny =y + j - 1;
        if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
          v += M[nx][ny];
          ++cnt;
        }
      }
      if (cnt != 0) ans[i][j] = v / cnt;
    }
    return ans;
  }
};
