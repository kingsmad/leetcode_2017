#include <bits/stdc++.h>
using namespace std;
const int maxt = 1e6 + 10;
const int maxp = 1e3 + 10;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    int* fail = new int[needle.size()+1]; 
    int ans = kmp(needle, haystack, fail);
    delete[] fail;
    return ans;
  }
  
  void getFail(const string& p, int* fail) {
    int i, j = -1, n = p.size(); 
    for (i=0; i<n; ++i, ++j) {
      fail[i] = (~j && p[i] == p[j]) ? fail[j] : j;
      while(~j && p[i] != p[j]) j = fail[j];
    }
    fail[i] = j;
  }

  int kmp(const string& p, const string& t, int* fail) {
    int i, j = 0;
    getFail(p, fail);
    for (i=0; i<t.size(); ++i) {
      while(~j && t[i] != p[j]) j = fail[j];
      if (++j == p.size()) {
        return i - p.size() + 1;
      }
    }
    return -1;
  }

};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  const string t = "babba", p = "bbb";
  Solution sol;
  int ans = sol.strStr(t, p);
  printf("%d\n", ans);
  return 0;
}
#endif
