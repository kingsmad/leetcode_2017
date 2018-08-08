#include <bits/stdc++.h>
using namespace std;
int row, col;
class Solution {
 public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    row = A.size();
    if (row == 0) return A;
    col = A.at(0).size();

    for (int i = 0; i < row; ++i) {
      int p = 0, q = col - 1;
      while (p < q) {
        swap(A[i][p], A[i][q]);
        ++p, --q;
      }
      for (int j=0; j<col; ++j) A[i][j] = !A[i][j];
    }

    return A;
  }
};
