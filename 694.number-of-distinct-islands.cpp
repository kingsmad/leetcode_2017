#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
using namespace std;

const int maxn = 55;
bool vis[maxn][maxn];
int bcc[maxn][maxn];
const int rs[4] = { 0, 0, 1, -1};
const int cs[4] = { -1, 1, 0, 0};

class Solution {
   int row, col;
 public:
  void dfs(int r, int c, const int bccno, vector<vector<int>>& grid) {
    if (r >= row || r < 0 || c >= col || c < 0) return;
    if (vis[r][c] || grid[r][c] == 0) return; 
    vis[r][c] = true;
    bcc[r][c] = bccno;
    for (int i=0; i<4; ++i) dfs(r+rs[i], c+cs[i], bccno, grid);
  }

  bool IsEqual(const vector<pair<int, int>>& v1, const vector<pair<int, int>>& v2) {
    if (v1.size() != v2.size()) return false;
    for (int i=0; i<v1.size(); ++i) {
      if (v1.at(i) != v2.at(i)) return false;
    }
    return true;
  }

  int numDistinctIslands(vector<vector<int>>& grid) {
    row = grid.size();
    if (row == 0) return 0;
    col = grid.at(0).size();

    memset(vis, 0, sizeof(vis));
    memset(bcc, 0, sizeof(bcc));
    int bcnt = 1;
    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
      if (!vis[i][j] && grid[i][j] == 1) {
        dfs(i, j, bcnt++, grid);
      }
    }

    map<int, vector<pair<int, int>> > bn2nodes;
    for (int i=0; i<row; ++i) for (int j=0; j<col; ++j) {
      if (grid[i][j] == 0) continue;
      bn2nodes[bcc[i][j]].push_back(make_pair(i, j));
    }

    // modify nodes in each bcc
    for (int d=1; d<bcnt; ++d) {
      vector<pair<int, int>>& v = bn2nodes.at(d);
      int mr = v.front().first, mc = v.front().second; 
      for (const pair<int, int>& p : v) {
        mr = min(mr, p.first);
        mc = min(mc, p.second);
      }
      for (pair<int, int>& p : v) {
        p.first -= mr;
        p.second -= mc;
      }
      sort(v.begin(), v.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second < p2.second;
      });
    }

    set<int> ans;
    for (int i=1; i<bcnt; ++i) {
      bool found = false;
      for (int j : ans) {
        const vector<pair<int, int>>& v1 = bn2nodes.at(i);            
        const vector<pair<int, int>>& v2 = bn2nodes.at(j);            
        if (!IsEqual(v1, v2)) continue;
        else { found = true; break;}
      }
      if (!found) ans.insert(i);
    }

    return ans.size();
  }
};
