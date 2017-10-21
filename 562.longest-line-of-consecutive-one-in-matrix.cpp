#include <vector>
using namespace std;

class Solution {
 public:
  void Check(int x, int y, int& ans, vector<vector<int>>& M) {
    int r = M.size(), c = M.at(0).size();
    if (M[x][y] == 0) return;
    int p = y, q = y;
    while (p >= 0 && M[x][p] == 1) --p;
    while (q < c && M[x][q] == 1) ++q;
    ans = max(ans, q - p - 1);

    p = x, q = x;
    while (p >= 0 && M[p][y] == 1) --p;
    while (q < r && M[q][y] == 1) ++q;
    ans = max(ans, q - p - 1);

    p = x, q = y;
    while (p >= 0 && p < r && q >= 0 && q < c && M[p][q] == 1) { --p, --q; }
    int t1 = x - p;
    p = x, q = y;
    while (p >= 0 && p < r && q >= 0 && q < c && M[p][q] == 1) { ++p, ++q; }
    int t2 = p - x;
    ans = max(ans, t1 + t2 - 1);

    p = x, q = y;
    while (p >= 0 && p < r && q >= 0 && q < c && M[p][q] == 1) { --p, ++q; }
    t1 = x - p;

    p = x, q = y;
    while (p >= 0 && p < r && q >= 0 && q < c && M[p][q] == 1) { ++p, --q; }
    t2 = p - x;
    ans = max(ans, t1 + t2 - 1);

    return;
  }

  int longestLine(vector<vector<int>>& M) {
    int r = M.size();
    if (r == 0) return 0;
    int c = M.at(0).size();

    int ans = 0;
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) Check(i, j, ans, M);
    return ans;
  }
};
