#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  void getFail(const string& p, vector<int>& fail) {
    int n = p.size();
    int i, j = -1;
    for (i=0; i<n; ++i, ++j) {
      fail[i] = (~j && p[i] == p[j]) ? fail[j] : j;
      while(~j && p[i] != p[j]) j = fail[j];
    }
    fail[i] = j;
  }

  void kmp(const string& p, const string& t, const vector<int>& fail) {
    int i, j = 0, ans = 0;  
    int pn = p.size(), tn = t.size();
    for (i=0; i<tn; ++i) {
      while(~j && t[i] != p[j]) j = fail[j];
      if (++j == pn) {
        ++ans;
        j = fail[j];
      }
    }
  }

  bool repeatedSubstringPattern(string s) {
    int n = s.size();
    vector<int> fail(s.size() + 1);
    getFail(s, fail);
    int p = n - fail[n];
#ifdef ROACH_ONLINE_JUDGE
    printf("%d\n", p);
#endif
    if (p == n || n % p != 0) return false;
    for (int i=0; i<n; i+=p) {
      for (int j=0; j<p; ++j) {
        if (s[i+j] != s[j]) return false;
      }
    }
    return true;
  }
};
#ifdef ROACH_ONLINE_JUDGE

int main(int, char**) {
  Solution sol;
  string str; cin >> str; 
  bool ok = sol.repeatedSubstringPattern(str);
  ok ? printf("YES\n") : printf("NO\n");
  return 0;
}
#endif

