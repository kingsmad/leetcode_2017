#include <set>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
 public:
  string predictPartyVictory(string senate) {
    int n = senate.size();
    list<int> rx, dx;
    for (int i=0; i<n; ++i) {
      if (senate.at(i) == 'R') rx.push_back(i);
      else dx.push_back(i);
    }

    int prd = 0, qrd = 0;
    auto p = rx.begin(), q = dx.begin();

    while(!rx.empty() && !dx.empty()) {
      if (*p + prd * n < *q + qrd * n) {
        auto c = q++;
        dx.erase(c);
        if (q == dx.end()) { ++qrd; q = dx.begin();}
        
        if (++p == rx.end()) { ++prd; p = rx.begin();}
      } else {
        auto c = p++;
        dx.erase(c);
        if (p == rx.end()) { ++prd; p = rx.begin();}

        if (++q == dx.end()) { ++qrd; q = dx.begin();}
      }
    }

    if (!rx.empty()) return "Radiant";
    else return "Dire";
  }
};
