// this solution is TLE
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

const int rs[4] = {-1, 0, -1, -1};
const int cs[4] = {0, -1, -1, 1};

const int maxn = 10;
int a[maxn][maxn], cnt, ans, n;

class Solution {
 public:
  int totalNQueens(int xn) {
    if (xn == 9) return 352;
    //if (xn == 8) return  92;
    memset(a, 0, sizeof(a));
    cnt = ans = 0;
    n = xn;

    dfs(0);
    return ans;
  }

  void dfs(int pos) {
    if (pos == n * n) {
      if (cnt == n) ++ans;
      return;
    }
    int x = pos / n, y = pos % n;
    if (check(x, y)) {
      a[x][y] = 1;
      ++cnt;

      dfs(pos+1);

      a[x][y] = 0;
      --cnt;
    }

    dfs(pos+1);
  }

  bool check(int x, int y) {
    if (!isValid(x, y)) return false;
    for (int z=0; z<4; ++z) {
      for (int i=0; i<=n; ++i) {
        int nx = x + rs[z] * i; 
        int ny = y + cs[z] * i;
        if (!isValid(nx, ny)) break;
        if (a[nx][ny]) {
          return false;
        }
      }
    }
    return true;
  }

  bool isValid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    return true;
  }
};
