#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int inf = 2e9 + 7;
inline int lowbit(int x) { return x & (-x);}

class Solution {
  vector<vector<int>> lx;
  int row, col;
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    row = matrix.size(), col = matrix.at(0).size();   
    init(matrix);
    

    ll ans = -inf;
    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
      for (int p=i; p<row; ++p) for (int q=j; q<col; ++q) {
        int v = sumRegion(i, j, p, q);
        if (v <= k && abs(k-v) < abs(k-ans)) ans = v;
      }
    }

    return ans;
  }

  void init(vector<vector<int>>& matrix) {
    lx = matrix;
    for (int i=0; i<row; ++i) for (int j=1; j<col; ++j) {
      lx[i][j] = lx[i][j-1] + lx[i][j];
    }
    for (int j=0; j<col; ++j) for (int i=1; i<row; ++i) {
      lx[i][j] = lx[i-1][j] + lx[i][j];
    }
  }

  inline int query(int x, int y) {
    if (x < 0 || y < 0) return 0;
    return lx[x][y];
  }

  int sumRegion(int r1, int c1, int r2, int c2) {
    int ans = query(r2, c2);
    ans -= query(r1-1, c2);
    ans -= query(r2, c1-1);
    ans += query(r1-1, c1-1);
    return ans;
  }

};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  Solution sol;
  int row, col, k; scanf("%d%d%d", &row, &col, &k);
  vector<vector<int>> matrix(row, vector<int>(col, 0));
  for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) scanf("%d", &matrix[i][j]); 
  int ans = sol.maxSumSubmatrix(matrix, k);
  printf("%d\n", ans);

  return 0;

}
#endif
