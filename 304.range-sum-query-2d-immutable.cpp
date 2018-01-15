#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
inline int lowbit(int x) { return x & (-x);}

struct FenwickTree {
  int nx, ny;
  vector<vector<int> > c;
  void init(int ntx, int nty) {
    nx = ntx, ny = nty;
    c.resize(nx + 1);
    for (int i=1; i<=nx; ++i) c[i].resize(ny+1, 0);
  }

  void update(int x, int y, int v) {
    ++x, ++y;
    for (int i=x; i<=nx; i+=lowbit(i)) 
      for (int j=y; j<=ny; j+=lowbit(j)) c[i][j] += v;
  }

  int query(int x, int y) {
    if (x < 0 || y < 0) return 0;
    ++x, ++y;
    ll ans = 0;
    for (int i=x; i>0; i-=lowbit(i))
      for (int j=y; j>0; j-=lowbit(j)) ans += c[i][j];
    return ans;
  }
};

class NumMatrix {
  FenwickTree ftree;
 public:
  NumMatrix(vector<vector<int>> matrix) {
    int row = matrix.size();
    if (row == 0) return;
    int col = matrix.at(0).size();
    ftree.init(row, col);
    for (int i=0; i<row; ++i) {
      for (int j=0; j<col; ++j) 
        ftree.update(i, j, matrix[i][j]);
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int ans = ftree.query(row2, col2);
    ans -= ftree.query(row1-1, col2);
    ans -= ftree.query(row2, col1-1);
    ans += ftree.query(row1-1, col1-1);
    return ans;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
