#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const double epi = 1e-7;
inline bool eq(double x, double y ) { return abs(x-y) < epi;}
class Solution {
 public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> a(101, vector<double>(101, 0.0));
    a[0][0] = poured;

    int r = 0;
    while(r+1 < 100) {
      for (int i=0; i<r+1; ++i) {
        if (a[r][i] < 1.0 || eq(a[r][i], 1.0)) continue;
        double f = (a[r][i] - 1.0); 
        a[r][i] = 1.0;
        a[r+1][i] += f/2.0;
        a[r+1][i+1] += f/2.0;
      }
      ++r;
    }

    return a[query_row][query_glass]; 
  }
};
