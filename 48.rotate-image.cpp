#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return;

    int x1 = 0, y1 = 0, x2 = n-1, y2 = n-1; 
    while(x1 < x2) {
      for (int i=0; i<x2-x1; ++i) {
        int v = matrix[x1+i][y1];
        matrix[x1+i][y1] = matrix[x2][y1+i];
        matrix[x2][y1+i] = matrix[x2-i][y2];
        matrix[x2-i][y2] = matrix[x1][y2-i];
        matrix[x1][y2-i] = v;
      }
      ++x1, ++y1, --x2, --y2;
    }

    return;
  }
};
