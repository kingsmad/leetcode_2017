#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll inf = (ll)INT_MAX + 10;

class Solution {
 public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> ans;
    ll low = lower, up = upper;
    for (int i=0; i<nums.size(); ++i) {
      ll d = nums[i];
      if (d < low) continue;
      if (d > up) break;
      if (d > low) {
        ans.push_back(calc(low, d-1));
      }
      low = d + 1;
    }

    if (low <= up) ans.push_back(calc(low, up));
    return ans;
  }

  const string calc(int x, int y) {
    char b[100];
    if (x != y)
      sprintf(b, "%d->%d", x, y);
    else
      sprintf(b, "%d", x);
    return string(b);
  }
};
