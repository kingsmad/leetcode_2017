#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 10;
int low, up;

class Solution {
 public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    low = lower, up = upper;
    int n = nums.size();
    return div(0, n, nums);
  }

  int div(int l, int r, const vector<int>& nums) {
    if (l == r) return 0;
    if (l + 1 == r) {
      return nums.at(l) >= low && nums.at(l) <= up;
    }
    int md = (l + r) / 2;
    int ans = div(l, md, nums) + div(md, r, nums);

    vector<ll> sum({nums.at(md)});
    for (int i = md + 1; i < r; ++i) { sum.push_back(sum.back() + nums.at(i)); }

    sort(sum.begin(), sum.end());
    
    ll pre = 0;
    for (int i=md-1; i>=l; --i) {
      pre += nums.at(i); 
      int p = lower_bound(sum.begin(), sum.end(), low - pre) - sum.begin();
      int q = upper_bound(sum.begin(), sum.end(), up - pre) - sum.begin();
      ans += q - p;
    }
    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  vector<int> nums = {-2, 5, -1};
  int lower = -2, upper = 2;
  Solution sol;
  int ans = sol.countRangeSum(nums, lower, upper);
  printf("%d\n", ans);
  return 0;
}
#endif
