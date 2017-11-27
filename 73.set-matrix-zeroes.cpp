#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int row = matrix.size();
    if (row == 0) return;
    int col = matrix.at(0).size();

    int r = -1, c = -1;
    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
      if (matrix[i][j] == 0) {
        r = i, c = j;
        break;
      }
    }

    if (r == -1 || c == -1) return;

    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
      if (matrix[i][j] == 0) {
        matrix[r][j] = matrix[i][c] = 0;
      }
    }

    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
      if (i == r || j == c) continue;
      if (matrix[i][c] == 0 || matrix[r][j] == 0) matrix[i][j] = 0;
    }

    for (int i=0; i<row; ++i) matrix[i][c] = 0;
    for (int j=0; j<col; ++j) matrix[r][j] = 0;
  }
};
