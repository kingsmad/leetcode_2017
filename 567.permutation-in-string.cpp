#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
 public:
  bool Check(int* p, int* q) {
    for (int i=0; i<26; ++i) if (p[i] != q[i]) return false;
    return true;
  }

  bool checkInclusion(string s1, string s2) {
    int n1 = s1.size();
    if (s2.size() < n1) return false;

    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for (char c : s1) ++cnt[c-'a'];

    int scnt[26];
    memset(scnt, 0, sizeof(scnt));

    int p = 0, q = 0;
    while(p + n1 <= s2.size()) {
      while(q < p + n1) ++scnt[s2[q++] - 'a'];
      if (Check(cnt, scnt)) return true;
      --scnt[s2[p++] - 'a'];
    }

    return false;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  Solution sol;
  string s1, s2; cin >> s1 >> s2;

  bool r = sol.checkInclusion(s1, s2);
  if (r) printf("YES\n");
  else printf("NO\n");

  return 0;
}
#endif
