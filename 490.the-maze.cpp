#include <iostream>
#include <vector>

using namespace std;
const int maxn = 1e4 + 10;
int r, c;
int fa[maxn];
int findset(int x) { return (x == fa[x]) ? x : (fa[x] = findset(fa[x])); }
void join(int x, int y) {
  int u = findset(x), v = findset(y);
  if (u == v) return;
  fa[u] = v;
}

class Solution {
 public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start,
               vector<int>& destination) {
    r = maze.size(), c = maze.at(0).size();
    for (int i = 0; i < Sid(r-1, c-1); ++i) fa[i] = i;

    // single islands
    Link(start.at(0), start.at(1), maze);
    Link(destination.at(0), destination.at(1), maze);

    // roads
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c;) {
        while (j < c && maze[i][j] == 0) ++j;
        if (j > 0) join(Sid(i, 0), Sid(i, j-1));
        if (j == c) break;

        int q = j + 1;
        while (q < c && maze[i][q] == 0) ++q;
        if (q - j >= 1) join(Sid(i, j + 1), Sid(i, q - 1));

        j = q + 1;
      }
    }

    for (int j = 0; j < c; ++j) {
      for (int i = 0; i < r; ) {
        while (i < r && maze[i][j] == 0) ++i;
        if (i > 0) join(Sid(0, j), Sid(i-1, j));
        if (i == r) break;

        int q = i + 1;
        while (q < r && maze[q][j] == 0) ++q;
        if (q - i >= 1) join(Sid(i + 1, j), Sid(q - 1, j));

        i = q + 1;
      }
    }

    return findset(Sid(start[0], start[1]))
           == findset(Sid(destination[0], destination[1]));
  }

  void Link(int x, int y, const vector<vector<int> > & maze) {
    int p = x-1;     
    while(p >= 0 && maze[p][y] == 0) --p;
    join(Sid(p+1, y), Sid(x, y));

    p = x + 1;
    while(p < r && maze[p][y] == 0) ++p;
    join(Sid(p-1, y), Sid(x, y));

    int q = y - 1;
    while(q >= 0 && maze[x][q] == 0) --q;
    join(Sid(x, q+1), Sid(x, y));

    q = y + 1;
    while(q < c && maze[x][q] == 0) ++q;
    join(Sid(x, q-1), Sid(x, y));
  }
  

  int Sid(int x, int y) { return x * c + y; }
};
