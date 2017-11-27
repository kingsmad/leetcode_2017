#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int cur = 1; 

    int x1 = 0, y1 = 0, x2 = n-1, y2 = n-1;
    while(x1 <= x2) {
      for (int i=y1; i<=y2; ++i) matrix[x1][i] = cur++;
      for (int i=x1+1; i<=x2; ++i) matrix[i][y2] = cur++;
      for (int i=y2-1; i>=y1; --i) matrix[x2][i] = cur++;
      for (int i=x2-1; i>x1; --i) matrix[i][y1] = cur++;
      ++x1, ++y1, --x2, --y2;
    }
     
    return matrix;
  }
};
