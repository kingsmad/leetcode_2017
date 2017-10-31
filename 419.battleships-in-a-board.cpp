#include <vector>
#include <string>

using namespace std;

const int rs[4] = { 0, 0, 1, -1};
const int cs[4] = {1, -1, 0 ,0};

int row, col;
class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    int ans = 0;
    row = board.size(), col = board.at(0).size();

    vector<vector<bool> > vis(row, vector<bool>(col, 0));

    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
      if (!vis[i][j] && board[i][j] == 'X') {
        dfs(i, j, board, vis, ans);
        ++ans;
      }
    }
     
        
    return ans;
  }

  void dfs(int x, int y, vector<vector<char>>& board, 
      vector<vector<bool>>& vis, int& ans) {
    if (x < 0 || x >= row || y < 0 || y >= col) return;
    if (vis[x][y] || board[x][y] != 'X') return;
    
    vis[x][y] = 1; 
    for (int i=0; i<4; ++i) {
      int nx = x + rs[i], ny = y + cs[i];
      dfs(nx, ny, board, vis, ans);
    }
  }
};
