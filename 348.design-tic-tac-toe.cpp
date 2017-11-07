#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int rs[2] = {1, 1};
const int cs[2] = {-1, 1};

class TicTacToe {
  vector<vector<int> > board;
  int n;
 public:
  /** Initialize your data structure here. */
  TicTacToe(int n) {
    this->n = n;
    board = vector<vector<int> > (n, vector<int>(n, -1));
  }

  /** Player {player} makes a move at ({row}, {col}).
      @param row The row of the board.
      @param col The column of the board.
      @param player The player, can be either 1 or 2.
      @return The current winning condition, can be either:
              0: No one wins.
              1: Player 1 wins.
              2: Player 2 wins. */
  int move(int row, int col, int player) {
    board[row][col] = player;
    if (Check(row, col, player)) return player;
    return 0;
  }

  bool Check(int x, int y, int v) {
    int p = x, q = x;
    while(p >= 0 && board[p][y] == v) --p;
    while(q < n && board[q][y] == v) ++q;
    if (q - p - 1== n) return true;

    p = y, q = y;
    while(p >= 0 && board[x][p] == v) --p;
    while(q < n && board[x][q] == v) ++q;
    if (q - p - 1 == n) return true;

    for (int dir = 0; dir < 2; ++dir) {
      int p = 0, q = 0; 
      while(IsValid(x + p * rs[dir], y + p * cs[dir], v)) --p;
      while(IsValid(x + q * rs[dir], y + q * cs[dir], v)) ++q;
      if (q - p -1 == n) return true;
    }
   
    return false;
  }

  inline bool IsValid(int x, int y, int v) {
    return x >= 0 && x < n && y >= 0 && y < n && board[x][y] == v;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
