#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
 public:
  int minPatches(vector<int>& nums, int n) {
    ll p = 1, cnt = 0, i = 0;
    while(p <= n) {
      if (i < nums.size() && nums[i] <= p) {
        p += nums[i++];
      } else {
        p += p;
        ++cnt;
      }
    }

    return cnt;
  }
};
