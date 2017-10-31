#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
using ll = long long;

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    const int n = nums.size();
    const int mod = k;

    if (k == 0) {
      for (int i=0; i<n; ) {
        while(i<n && nums.at(i) != 0) ++i; 
        if (i == n) break;
        int q = i + 1;
        while(q < n && nums.at(q) == 0) ++q;
        if (q - i >= 2) return true;
        i = q;
      }
      return false;
    }

    map<ll, int> smp;
    ll sum = 0;
    smp.emplace(0, 0);
    for (int i=1; i<=n; ++i) {
      sum = (sum + nums.at(i-1) + mod) % mod;
      if (smp.count(sum) > 0) {
        if (i - smp.at(sum) >= 2) return true;
      } else {
        smp.emplace(sum, i);
      }
    }

    return false;
  }
};
