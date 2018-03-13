#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int numMatchingSubseq(string S, vector<string>& words) {
    int n = S.size();
    vector<vector<int>> tb(26, vector<int>());
    for (int i=0; i<n; ++i) {
      tb[S[i]-'a'].push_back(i);
    }

    int ans = 0;
    for (const string& s : words) {
      int u = -1;
      bool ok = true;
      for (char c : s) {
        const vector<int>& vec = tb[c-'a'];
        int p = upper_bound(vec.begin(), vec.end(), u) - vec.begin();
        if (p == vec.size()) { ok = false; break;}
        u = vec[p];
      }
      if (ok) ++ans;
    }

    return ans;
  }
};
