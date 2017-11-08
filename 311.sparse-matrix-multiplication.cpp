#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int m = A.size(), k = A.at(0).size(), n = B.at(0).size();      
    vector<vector<int>> ans(m, vector<int>(n, 0));

    for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) {
      int v = 0;
      for (int z=0; z<k; ++z) {
        v += A[i][z] * B[z][j];
      }
      ans[i][j] = v;
    }

    return ans;
  }
};
