#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int longestSubstring(string s, int k) {
    int n = s.size();
    vector<int> hs(26, 0);
    for (int i=0; i<n; ++i) ++hs[s[i]-'a'];
    vector<bool> flag(n, false);
    for (int i=0; i<n; ++i) if (hs[s[i] - 'a'] >= k) flag[i] = true;

    int ans = 0;
    for (int i=0; i<n; ) {
      while(i < n && !flag[i]) ++i;
      if (i == n) break;
      int q = i + 1;
      while(q < n && flag[q]) ++q; 
      ans = max(ans, q - i); 
      i = q;
    }

    return ans;
  }
};
