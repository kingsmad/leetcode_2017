#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool validTicTacToe(vector<string>& board) {
    int cntx = 0, cnto = 0;
    for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) { 
      if (board[i][j] == 'X') ++cntx;
      if (board[i][j] == 'O') ++cnto;
    }

    if (cntx < cnto || cntx - cnto > 1) return false;

    int v = check(board);
    if (v == 1) return cntx == cnto + 1;
    if (v == 2) return cntx == cnto;
    if (v == 3) return false;

    return true;
  }

  int check(vector<string>& board) {
    int ans = 0;
    for (int i=0; i<3; ++i) {
      int cnt = 0;
      for (int j=0; j<3; ++j) { 
        if (board[i][j] == 'O') cnt += 1;
        else if (board[i][j] == 'X') cnt += 10;
      }
      if (cnt % 10 == 3) ans |= (1<<1); 
      if (cnt >= 30) ans |= (1<<0); 
    }

    for (int j=0; j<3; ++j) {
      int cnt = 0;
      for (int i=0; i<3; ++i) {
        if (board[i][j] == 'O') cnt += 1;
        else if (board[i][j] == 'X') cnt += 10;
      }
      if (cnt % 10 == 3) ans |= (1<<1); 
      if (cnt >= 30) ans |= (1<<0); 
    }

    int cnt = 0;
    cnt = (board[0][0]=='X') + (board[1][1]=='X') +( board[2][2]=='X');
    if (cnt == 3) ans |= (1<<0);

    cnt = (board[0][0]=='O') + (board[1][1]=='O') +( board[2][2]=='O');
    if (cnt == 3) ans |= (1<<1);

    cnt = (board[0][2]=='X') + (board[1][1]=='X') +( board[2][0]=='X');
    if (cnt == 3) ans |= (1<<0);

    cnt = (board[0][2]=='O') + (board[1][1]=='O') +( board[2][0]=='O');
    if (cnt == 3) ans |= (1<<1);

    return ans;
  }
};
