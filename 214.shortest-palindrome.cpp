#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 10;

class Solution {
 public:
  string shortestPalindrome(string s) {
    string str = s;
    reverse(str.begin(), str.end());
    str = s + "#" + str;
    vector<int> f(s.size() * 2 + 10, 0);
    getFail(str, &f[0]);

    int v = f[2*s.size()+1];

    string ans = s.substr(v, s.size());
    reverse(ans.begin(), ans.end());
    return ans + s;
  }

  void getFail(const char* p, int* fail) {
    int i, j = -1;
    for (i=0; p[i]; ++i, ++j) {
      fail[i] = (~j && p[i] == p[j]) ? fail[j] : j;
      while(~j && p[i] != p[j]) j = fail[j];
    }
    fail[i] = j;
  }

  void getFail(const string& p, int* fail) {
    int n = p.size();
    int i, j = -1;
    for (i=0; i<n; ++i, ++j) {
      fail[i] = (~j && p[i] == p[j]) ? fail[j] : j;
      while(~j && p[i] != p[j]) j = fail[j];
    }
    fail[i] = j;
  }

  
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  Solution sol;
  string str = "aacecaaa";
  string ans = sol.shortestPalindrome(str);
  cout << ans << endl;
  return 0;
}
#endif
