#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int row, col;
vector<vector<int> > board;

class Solution {
 public:
  vector<vector<int>> candyCrush(vector<vector<int>>& myboard) {
    board = myboard;
    row = board.size();
    if (row == 0) return board;
    col = board.at(0).size();

    while(1) {
      if (!crush()) break;
      maintain();
    }
      
    return board;
  }

  bool crush() {
    for (int i=0; i<row; ++i) {
      for (int j=0; j<col; ) {
        int q = j + 1;
        while(q < col && abs(board[i][q]) == abs(board[i][j])) ++q;
        if (q - j >= 3) {
          for (int x=j; x<q; ++x) board[i][x] = -abs(board[i][x]);
        }
        j = q;
      }
    }

    for (int j=0; j<col; ++j) {
      for (int i=0; i<row; ) {
        int q = i + 1;
        while(q < row && abs(board[q][j]) == abs(board[i][j])) ++q;
        if (q - i >= 3) {
          for (int x=i; x<q; ++x) board[x][j] = -abs(board[x][j]);
        }
        i = q;
      }
    }

    bool done = false;
    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) if (board[i][j] < 0) {
      done = true;
      board[i][j] = 0;
    }
    return done;
  }

  void maintain() {
    for (int i=row-2; i>=0; --i) for (int j=0; j<col; ++j) {
      if (board[i][j] == 0) continue;
      int p = i;
      while(p+1 < row && board[p+1][j] == 0) {
        swap(board[p][j], board[p+1][j]);
        ++p;
      }
    }
  }
};
