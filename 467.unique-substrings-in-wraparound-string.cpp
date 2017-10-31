#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
map<int, int> smp;


class Solution {
 public:
  int findSubstringInWraproundString(string p) {
    smp.clear();
    int n = p.size();
    for (int i=0; i<n; ) {
      int q = i + 1; 
      while(q < n && (p.at(q) - p.at(q-1) + 26) % 26 == 1) ++q;

      for (int j=i; j<q; ++j) {
        int x = p.at(j);
        if (smp.count(x) == 0) smp[x] = 0;
        smp[x] = max(smp[x], q - j);
      }

      i = q;
    }

    int ans = 0;
    for (auto& p : smp) ans += p.second; 

    return ans;
  }
};
