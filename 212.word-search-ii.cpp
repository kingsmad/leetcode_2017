#include <bits/stdc++.h>

using namespace std;
const int maxnode = 1e5 + 10;
const int rs[4] = {0, 0, 1, -1};
const int cs[4] = {1, -1, 0, 0};
const int sigma_sz = 26;

int row, col;
struct Trie {
  int ch[maxnode][sigma_sz], val[maxnode], sz, path[maxnode];
  void init() {
    memset(ch, 0, sizeof(ch));
    memset(val, 0, sizeof(val));
    memset(path, 0, sizeof(path));
    sz = 1;
  }

  void insert(const string& s) {
    int u = 0;
    for (char c : s) {
      int x = c - 'a';
      if (ch[u][x] == 0) ch[u][x] = sz++;
      u = ch[u][x];
      ++path[u];
    }
    val[u] = 1;
  }

  int query(const string& s) {
    int u = 0;
    for (char c : s) {
      int x = c - 'a';
      if (ch[u][x] == 0 || path[ch[u][x]] == 0) return 0;
      u = ch[u][x];
    }

    return val[u] ? 1 : 2;
  }

  void Del(const string& s) {
    int u = 0;
    for (char c : s) {
      int x = c - 'a';
      u = ch[u][x];
      assert(u != 0);
      --path[u];
    }
  }
} trie;

class Solution {
  set<string> ans;

 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    row = board.size();
    col = board.at(0).size();

    trie.init();
    ans.clear();
    for (const string& s : words) trie.insert(s);

    vector<vector<int>> vis(row + 1, vector<int>(col + 1, 0));
    for (int i = 0; i < row; ++i)
      for (int j = 0; j < col; ++j) {
        string s;
        dfs(i, j, s, board, vis);
      }
    return vector<string>(ans.begin(), ans.end());
  }

  void dfs(int x, int y, string& path, const vector<vector<char>>& board,
           vector<vector<int>>& vis) {
    if (x < 0 || x >= row || y < 0 || y >= col || vis[x][y]) return;

    vis[x][y] = 1;
    path.push_back(board[x][y]);

    int qv = trie.query(path);
    if (qv == 1) {
      ans.insert(path);
      //trie.Del(path);
    } 
    if (qv > 0) {
      for (int z = 0; z < 4; ++z) {
        int nx = rs[z] + x, ny = cs[z] + y;
        dfs(nx, ny, path, board, vis);
      }
    }

    path.pop_back();
    vis[x][y] = 0;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  vector<vector<char>> board = {{'b', 'b', 'a', 'a', 'b', 'a'},
                                {'b', 'b', 'a', 'b', 'a', 'a'},
                                {'b', 'b', 'b', 'b', 'b', 'b'},
                                {'a', 'a', 'a', 'b', 'a', 'a'},
                                {'a', 'b', 'a', 'a', 'b', 'b'}};
  vector<string> words = {"abbbababaa"};

  Solution sol;
  vector<string> ans = sol.findWords(board, words);

  for (const string& s : ans) cout << s << endl;
  return 0;
}
#endif
