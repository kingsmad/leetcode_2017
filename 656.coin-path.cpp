// lexi order must be considered with current position.
// e.x 1,2,3 < 1,3 if we do not consider 3, there is error
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  const int inf = 1e9 + 10;

  bool Cmp(const vector<int>& v1, const vector<int>& v2) {
    for (int i=0; i<v1.size(); ++i) {
      if (i >= v2.size() || v1.at(i) > v2.at(i)) return false;
      if (v1.at(i) < v2.at(i)) return true;
    }
    return false;
  }

 public:
  vector<int> cheapestJump(vector<int>& A, int B) {
    if (A.size() == 0 || A.at(0) == -1) return vector<int>();

    int n = A.size();
    vector<vector<int>> path(n, vector<int>());
    vector<int> dp(n, inf);
    vector<int> fa(n, -1);
    dp[0] = 0;

    for (int i=0; i<n; ++i) {
      if (A[i] == -1 || dp[i] == inf) continue;
      for (int j=i+1; j<=min(n-1, i+B); ++j) {
        if (A[j] == -1) continue;
        bool ok = false;
        if (dp[j] > dp[i] + A[j]) ok = true;
        else if (dp[j] == dp[i] + A[j]) {
          path[j].push_back(j);
          path[i].push_back(i);
          path[i].push_back(j);
          if (Cmp(path[i], path[j])) ok = true;
          path[i].pop_back();
          path[i].pop_back();
          path[j].pop_back();
        }
        if (ok) {
          dp[j] = dp[i] + A[j];
          fa[j] = i;
          path[j] = path[i];
          path[j].push_back(i);
        }
      }
    }

    vector<int> ans;
    if (dp[n-1] == inf) return ans;
    int ps = n-1;
    do {
      ans.push_back(ps);
      ps = fa[ps];
    } while (ps != -1);

    for (int& d: ans) ++d;
    return vector<int>(ans.rbegin(), ans.rend());
  }
};
