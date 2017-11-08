#include <algorithm>
#include <string>
#include <vector>

using namespace std;
inline int lowbit(int x) { return x & (-x);}

class NumMatrix {
  vector<vector<int> > d;
  int row, col;
 public:
  NumMatrix(vector<vector<int>> matrix) {
    row = matrix.size();
    col = matrix.at(0).size();
    d = vector<vector<int>>(row, vector<int>(col, 0));
  }

  int sumRegion(int row1, int col1, int row2, int col2) {

  }

  void add(int x, int y, int v) {
    for (int i=x; i<=row; i+=lowbit(i)) for (int j=y; j<=col; j+=lowbit(j)) {
      d[i][j] += v;
    }
  }

  int sum(int x, int y) {
    int ans = 0;
    for (int i=x; i; i-=lowbit(i)) for (int j=y; j; j-=lowbit(j)) {
      ans += d[i][j];
    }
    return ans;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
