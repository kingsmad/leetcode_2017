#include <cstring>
#include <vector>
#include <string>

using namespace std;

const int maxcost = 110;
const int maxn = 1e3 + 10;

int x[maxn], y[maxn]; 
int dp[maxcost][maxcost][maxn];

class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    memset(dp, -1, sizeof(dp));
    
    for (int i=0; i<strs.size(); ++i) Parse(strs.at(i), i);

    return Calc(m, n, strs.size()-1);
  }

  void Parse(const string& s, int sid) {
    for (char c : s) if (c == '0') ++x[sid]; else ++y[sid];
  }

  int Calc(int p, int q, int k) {
    if ( k < 0) return 0;
    if (dp[p][q][k] != -1) return dp[p][q][k];

    dp[p][q][k] = Calc(p, q, k-1);

    if (p >= x[k] && q >= y[k]) {
      dp[p][q][k] = max(dp[p][q][k], Calc(p - x[k], q - y[k], k-1) + 1);  
    }
    return dp[p][q][k];
  }

};

