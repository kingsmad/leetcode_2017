#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int rs[4] = { 0, 0, 1, -1};
const int cs[4] = { 1, -1, 0, 0};

class Solution {
 int row, col;
 public:
  bool exist(vector<vector<char>>& board, string word) {
    row = board.size();
    if (row == 0) return false;
    col = board.at(0).size();

    vector<vector<bool> > vis(row, vector<bool>(col, false));
    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
      //printf("new at %d %d\n", i, j);
      if (dfs(i, j, board, 0, word, vis)) return true;
    }
    return false;
  }

  bool dfs(int x, int y, vector<vector<char>>& board, int p, 
           const string word, vector<vector<bool>>& vis) {
    if (p == word.size()) return true;
    if (!isValid(x, y)) return false;
    if (vis[x][y]) return false;
    if (word.at(p) != board[x][y]) return false;

    vis[x][y] = true;

    for (int z=0; z<4; ++z) {
      int nx = x + rs[z], ny = y + cs[z];
      if (dfs(nx, ny, board, p+1, word, vis)) return true;
    }

    vis[x][y] = false;
    return false;
  }

  bool isValid(int x, int y) {
    return x >= 0 && x <row && y >= 0 && y < col;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  string word; cin >> word;
  int row, col; scanf("%d%d", &row, &col); 
  vector<vector<char>> board(row, vector<char>(col, 0));
  for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
    char c[10];
    scanf("%s", c);
    board[i][j] = c[0]; 
  }

  Solution sol;
  bool ans = sol.exist(board, word);
  if (ans) printf("YES\n");
  else printf("NO\n");

  return 0;
}
#endif
