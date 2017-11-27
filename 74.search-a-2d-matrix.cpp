#include <vector>
#include <string>
#include <iostream>

using namespace std;

int row, col;
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    row = matrix.size();
    if (row == 0) return false;
    col = matrix.at(0).size();

    int l = 0, r = row * col;    
    while(l < r) {
      int md = (l+r) / 2;
      const pair<int, int> pii = Sid(md);
      int x = pii.first, y = pii.second;
      if (matrix[x][y] < target) l = md + 1;
      else if (matrix[x][y] > target) r = md;
      else return true;
    }

    return false;
  }

  inline int Sid(int x, int y) {
    return x * col + y;
  }

  inline const pair<int, int> Sid(int x) {
    int r = x / col;
    int c = x % col;
    return make_pair(r, c);
  }
};
