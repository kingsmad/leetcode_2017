#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int cap = nums.back() - nums.front(); 
    int l = 0, r = cap+1, target = n * (n-1) / 2 - k;
    while(l < r) {
      int md = (l+r)/2;
      if (calc(md, nums) > target) l = md + 1;
      else r = md;
    }
    return l;
  }

  int calc(int x, const vector<int>& nums) {
    int n = nums.size();
    int q = 0, ans = 0;
    for (int i=0; i<n; ++i) {
      while(q < n && nums.at(q) - nums.at(i) <= x) ++q; 
      if (q == n) break;
      ans += n - q; 
    }
    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char** ) {
  Solution sol;
  vector<int> nums = {1, 3, 1};
  int k = 1;
  int ans = sol.smallestDistancePair(nums, k);
  printf("%d\n", ans);
  return 0;
}
#endif
