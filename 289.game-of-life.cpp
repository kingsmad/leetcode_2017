#include <iostream>
#include <vector>

using namespace std;

const int rs[8] = {0 ,0 , -1, 1, 1, -1, -1, 1};
const int cs[8] = {1, -1, 0, 0, -1, 1, -1, 1};

class Solution {
  int row, col;
 public:
  void gameOfLife(vector<vector<int>>& board) {
    row = board.size(); 
    if (row == 0) return;
    col = board.at(0).size();

    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
      int cnt = 0;
      for (int k=0; k<8; ++k) {
        int nx = i + rs[k], ny = j + cs[k];
        if (IsValid(nx, ny) && board[nx][ny] % 10 == 1) ++cnt;
      }
      if (cnt < 2) board[i][j] += 0 * 10;
      if (cnt == 2 && board[i][j] % 10 == 1) board[i][j] += 1 * 10;
      if (cnt == 3) board[i][j] += 1 * 10;
      if (cnt > 3) board[i][j] += 0 * 10;
    }

    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) 
      board[i][j] = board[i][j] / 10;
    return;
  }

  bool IsValid(int x, int y) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }
};
