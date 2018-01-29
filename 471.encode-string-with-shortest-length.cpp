#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int maxn = 200;
int n, dp[maxn][maxn], a[maxn][maxn];

class Solution {
 public:
  string encode(string s) {
    memset(a, -1, sizeof(a));
    memset(dp, -1, sizeof(dp)); 
    for (int i=0; i+1<n; ++i) {
      dp[i][i+1] = 1;
      a[i][i+1] = i;
    }

    for (int step=2; step<n; ++step) {
      for (int i=0; i+step<=n; ++i) {
        dp[i][i+step] = calc(i, i+step);
        for (int k=a[i][i+step-1]; k<=a[i+1][i+step]; ++k) {
          dp[i][i+step] = min(dp[i][i+step], dp[i][k] + dp[k][i+step]);
        }
      }
    }

  }

  int calc(int l, int r, const string& s) {
    int len = r - l; int  ans = len;
    for (int bsz=len; bsz>=1; --bsz) {
      if (len % bsz != 0) continue;
      bool check = true;
      for (int i=0; i<bsz; ++i) {
        if (!check) break;
        char c = s.at(l+i);
        for (int j=i; j<len; j+=bsz) {
          if (s.at(l+j) != c) {
            check = false;
            break;
          }
        }
      }
      if (check) {
        ans = min(ans, 
      }
      
      
    }
    
  }
};
