#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
  int row, col;
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    row = matrix.size();
    if (row == 0) return ans;
    col = matrix.at(0).size();

    vector<pair<int, int> > points;
    for (int j=0; j<col; ++j) points.emplace_back(0, j);
    for (int i=1; i<row; ++i) points.emplace_back(i, col-1);

    vector<int> tmp;
    for (int i=0; i<points.size(); ++i) {
      auto& p = points.at(i);
      tmp.clear();
      int x = p.first, y = p.second; 
      while(isValid(x, y)) {
        tmp.push_back(matrix[x][y]);
        ++x, --y;
      }
      if (i % 2 == 0) reverse(tmp.begin(), tmp.end());

      for (int d : tmp) ans.push_back(d);
    }

    return ans;
  }

  bool isValid(int x, int y) {
    return x >= 0 && x < row && y >=0 && y < col;
  }

};
