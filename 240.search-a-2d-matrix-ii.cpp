#include <algorithm>
#include <vector>

using namespace std;
int n, m;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    n = matrix.size();
    if (n  == 0) return false;
    m = matrix.at(0).size();

    for (int i=0; i<n; ++i) {
      auto it = lower_bound(matrix[i].begin(), matrix[i].end(), target);
      if (it != matrix[i].end() && *it == target) return true;
    }

    return false;
  }
};
