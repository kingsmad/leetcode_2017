#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end());
    for (int i=n; i>=0; --i) {
      if (n-i >= 0 && n-i <n && citations.at(n-i) < i) continue;
      if (n-i-1 >=0 && n-i-1 <n && citations.at(n-i-1) > i) continue;
      return i;
    }
    return 0;
  }
};
