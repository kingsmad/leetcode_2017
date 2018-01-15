#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
const int maxn = 1e4 + 10;
int cnt[maxn][26], n;

class Solution {
 public:
  int characterReplacement(string s, int k) {
    n = s.size();
    memset(cnt, 0, sizeof(cnt));
    for (int i=1; i<=n; ++i) {
      for (int z=0; z<26; ++z) {
        cnt[i][z] = cnt[i-1][z] + (s[i-1] == 'A' + z);    
      }
    }

    int q = 0, ans = 0;
    for (int i=0; i<n; ++i) {
      q = max(q, i); 
      while(q+1 <= n && query(i, q+1) <= k) ++q;
      ans = max(ans, q - i);
    }

    return ans;
  }

  int query(int x, int y) {
    int mx = 0;
    for (int i=0; i<26; ++i) {
      mx = max(mx, cnt[y][i] - cnt[x][i]);
    }
    return y - x - mx;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  string str; cin >> str;
  int k; cin >> k;
  Solution sol;
  int ans = sol.characterReplacement(str, k);
  printf("%d\n", ans);
  return 0;

}
#endif
