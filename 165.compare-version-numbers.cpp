#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    int p = 0, q = 0;
    int n1 = version1.size(), n2 = version2.size();
    while(1) {
      if (p >= n1 && q >= n2) break;

      int pe = p + 1, qe = q + 1;
      while(pe < n1 && version1.at(pe) != '.') ++pe;
      while(qe < n2 && version2.at(qe) != '.') ++qe;
      int d1 = 0, d2 = 0;
      for (int i=p; i<pe && i<n1; ++i) d1 = d1 * 10 + version1.at(i) - '0';
      for (int i=q; i<qe && i<n2; ++i) d2 = d2 * 10 + version2.at(i) - '0';
      if (d1 != d2) return (d1 < d2) ? -1 : 1;
      p = pe+1, q = qe+1;
    }

    return 0;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  Solution sol;
  string s1, s2; cin >> s1 >> s2;
  int ans = sol.compareVersion(s1, s2);
  printf("%d\n", ans);
  return 0;
}
#endif
