#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

multiset<ll> ms;
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int n = nums.size();
    if (n < 2) return false;
    ms.clear();

    int p = 1, q = 1;
    for (int i=0; i<n; ++i) {
      while(q < min(n, i+k+1)) { ms.insert(nums.at(q++));}
      while(p <= i) {
        auto it = ms.find(nums.at(p));
        if (it != ms.end()) ms.erase(it);
        ++p;
      }

      auto lc = ms.lower_bound((ll)nums.at(i) - t);
      auto rc = ms.upper_bound((ll)nums.at(i) + t);
      if (lc != ms.end() && rc != ms.begin() && lc != rc) 
        return true;
    }
    return false;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  int n; scanf("%d", &n);
  vector<int> nums(n, 0);
  for (int i=0; i<n; ++i) scanf("%d", &nums[i]);
  int k, t; scanf("%d%d", &k, &t);
  Solution sol;
  int ans = sol.containsNearbyAlmostDuplicate(nums, k, t);
  printf("%d\n", ans);
  return 0;
}
#endif
