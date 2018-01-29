#include <cstring>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
const int maxn = 500 + 10;
int a[maxn][maxn], b[maxn][maxn];

class Solution {
 public:
  int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) { b[i][j] = 1; a[i][j] = N+1;}
    for (auto& p: mines) {
      int x = p.front(), y = p.back();
      b[x][y] = 0;
    }

    for (int i=0; i<N; ++i) {
      for (int j=0; j<N; ) {
        while(j < N && b[i][j] == 0) ++j;
        if (j == N) break;
        int q = j + 1;
        while(q < N && b[i][q] == 1) ++q;

        // now the seg is found
        for (int z=j; z<q; ++z) {
          a[i][z] = min(a[i][z], q - z);
          a[i][z] = min(a[i][z], z - j + 1);
        }
        j = q;
      }
    }

    for (int j=0; j<N; ++j) {
      for (int i=0; i<N; ) {
        while(i < N && b[i][j] == 0) ++i;
        if (i == N) break;
        int q = i + 1;
        while(q < N && b[q][j] == 1) ++q;

        // now the seg is found now
        for (int z=i; z<q; ++z) {
          a[z][j] = min(a[z][j], q-z);
          a[z][j] = min(a[z][j], z-i+1);
        }

        i = q;
      }
    }

    int ans =0;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) { 
      if (b[i][j] == 1) ans = max(ans, a[i][j]);
    }
    return ans;
  }

};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
     
}
#endif
