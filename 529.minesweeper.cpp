#include <iostream>
#include <vector>

using namespace std;
int row, col;
const int rs[8] = {0, 0, -1, 1, 1, 1, -1, -1};
const int cs[8] = {1, -1, 0, 0, -1, 1, 1, -1};

class Solution {
 public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    row = board.size();
    col = board.at(0).size();
    int x = click.front(), y = click.back();
    if (board[x][y] == 'M') { board[x][y] = 'X'; return board; }

    dfs(x, y, board);
    return board;
  }
  
  int CountMine(int x, int y, const vector<vector<char>>& board) {
    int cnt = 0;
    for (int i=x-1; i<x-1+3; ++i) for (int j=y-1; j<y-1+3; ++j) {
      if (i < 0 || i >= row || j < 0 || j >= col) continue;
      if (board[i][j] == 'M') ++cnt;
    }
    //printf("%d %d has mine %d\n", x, y, cnt);
    return cnt;
  }

  void dfs(int x, int y, vector<vector<char>>& board) {
    if (x < 0 || x >= row || y < 0 || y >= col) return;
    if (board[x][y] != 'E') return;

    int v = CountMine(x, y, board);
    if (v > 0) {
      board[x][y] = v + '0';
      return;
    }

    board[x][y] = 'B';
    for (int z=0; z<8; ++z) {
      dfs(x+rs[z], y + cs[z], board);
    }
  }
};
