#include <vector>
#include <cstring>

using namespace std;
const int rs[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int cs[8] = {2, -2, 2, -2, 1, -1, 1, -1};
const int maxn = 25;
double a[2][maxn][maxn];

class Solution {
 public:
  double knightProbability(int N, int K, int r, int c) {
    int n = N, k = K;
    int cur = 0;
    memset(a, 0, sizeof(a));
    a[0][r][c] = 1.0;
    while(k--) {
      memset(&a[!cur][0][0], 0, maxn* maxn * sizeof(double));
      for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
        if (a[cur][i][j] > 0) {
          for (int z=0; z<8; ++z) {
            if (i+rs[z] < 0 || i+rs[z] >=n ) continue;
            if (j+cs[z] < 0 || j+cs[z] >=n ) continue;
            a[!cur][i+rs[z]][j+cs[z]] += a[cur][i][j] / 8.0;
          }
        }
      }
      cur = !cur;
    }

    double ans = 0.0;
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) ans += a[cur][i][j];
    return ans;
  }
};
