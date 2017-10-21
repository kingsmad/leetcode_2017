#include <iostream>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

using ll = long long;
ll sum[4];

class Solution {
 public:

  bool makesquare(vector<int>& nums) {
    if (nums.size() < 4) return false;
    memset(sum, 0, sizeof(sum));
    ll target = 0;
    for (int d : nums ) target += d;
    
    if (target % 4 != 0) return false;

    return dfs(0, nums, target/4);
  }

  bool dfs(int pos, vector<int>& nums, ll target) {
    if (pos == nums.size()) {
      for (int i=0; i<4; ++i) if (sum[i] != target) return false;
      return true;
    }

    int d = nums.at(pos);
    for (int i=0; i<4; ++i) {
      if (sum[i] + d <= target) {
        sum[i] += d; 
        if (dfs(pos+1, nums, target)) return true;
        sum[i] -= d;
      }
    }

    return false;
  }

};

