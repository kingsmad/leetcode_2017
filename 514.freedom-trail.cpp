#include <cstring>
#include <vector>
#include <iostream>

using namespace std;
const int maxn = 110;
const int inf = 1e9 + 10;
int n, m, dis[maxn][26], dp[maxn][maxn];

class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    n = key.size(), m = ring.size();
    calc_dis(ring);
    memset(dp, -1, sizeof(dp));
  }

  void calc_dis(const string& ring) {
    int n = ring.size();
    for (int i=0; i<n; ++i) fill(&dis[i][0], &dis[i][0]+26, inf);
    for (int i=0; i<n; ++i) {
      for (int s=0; s<n; ++s) {
        int c1 = ring.at((i+s)%n) - 'a';
        int c2 = ring.at((i+n-s)%n) - 'a';
        dis[i][c1] = min(dis[i][c1], s);
        dis[i][c2] = min(dis[i][c2], s);
      }
    }
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  /*freopen("in.txt", "r", stdin);
  string s1, s2; cin >> s1 >> s2; */
  string s1 = "godding", s2 = "gd";
  Solution sol;
  int ans = sol.findRotateSteps(s1, s2);
  printf("%d\n", ans);
  return 0;
}
#endif
