#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
 public:
  int findLUSlength(vector<string>& strs) {
    const int n = strs.size();
    int ans = -1;
    for (int i=0; i<n; ++i) {
      bool ok = true;
      for (int j=0; j<n; ++j) {
        if (i == j) continue;
        if (Check(strs.at(j), strs.at(i))) {
          ok = false;
          break;
        }
      }
      if (ok) ans = max(ans, static_cast<int>(strs.at(i).size()));
    }

    return ans;
  }

  bool Check(const string& s, const string& ts) {
    int p = s.size();
    for (int i=ts.size()-1; i>=0; --i) {
      while(p >= 0 && s[p] != ts[i]) --p;
      if (p == -1) return false;
      --p;
    }

    return true;
  }
};
