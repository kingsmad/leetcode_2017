#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int row, col;
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    row = matrix.size();
    if (row == 0) return ans;
    col = matrix.at(0).size();

    int x1 = 0, y1 = 0, x2 = row - 1, y2 = col - 1;
    while(x1 <= x2 && y1 <= y2) {
      for (int i=y1; i<=y2; ++i) ans.push_back(matrix[x1][i]); 
      for (int i=x1+1; i<=x2; ++i) ans.push_back(matrix[i][y2]);
      if (x1 != x2) for (int i=y2-1; i>=y1; --i) ans.push_back(matrix[x2][i]);
      if (y1 != y2) for (int i=x2-1; i>x1; --i) ans.push_back(matrix[i][y1]);
      ++x1, ++y1, --x2, --y2;
    }

    return ans;
  }
};
