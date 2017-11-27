#include <cstring>
#include <vector>
#include <string>

using namespace std;

const int rs[2] = {0, 1};
const int cs[2] = {1, 0};

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for (int i=0; i<9; ++i) {
      vector<bool> f(9, false);
      for (int j=0; j<9; ++j) {
        if (board[i][j] == '.') continue;
        if (f[board[i][j]-'1']) return false;
        f[board[i][j]-'1'] = true;
      }
    }

    for (int j=0; j<9; ++j) {
      vector<bool> f(9, false);
      for (int i=0; i<9; ++i) {
        int v = board[i][j];
        if (v == '.') continue;
        if (f[v-'1']) return false;
        f[v-'1'] = true;
      }
    }

    for (int i=0; i<9; i+=3) for (int j=0; j<9; j+=3) {
      bool f[10]; memset(f, 0, sizeof(f));
      for (int z=0; z<3; ++z) for (int t=0; t<3; ++t) {
        int v = board[i+z][j+t];
        if (v == '.') continue;
        v = v - '0';
        if (f[v]) return false;
        f[v] = true;
      }
    }

    return true;
  }
};
