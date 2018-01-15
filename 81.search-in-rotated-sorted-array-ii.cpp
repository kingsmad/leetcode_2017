#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return false;
    int l = 0, r = n;
    
    int st = find_start(nums);

    int len = n;
    while(len > 0) {
      int md = (st + len/2) % n;
      if (nums.at(md) == target) return true;
      if (nums.at(md) < target) {
        st = md + 1;
        len = len - len/2 - 1;
      } else {
        len = len / 2;
      }
    }
    return false;
  }

  // find the start point
  int find_start(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;
    int l = 0, r = n;
    while(l < n && nums.at(l) == nums.at(n-1)) ++l;
    if (l == n) return 0;
    if (nums.at(l) < nums.at(n-1)) return l;

    int pv = nums.at(l);
    while(l < r) {
      int md = (l+r) / 2;
      if (nums.at(md) >= pv) l = md + 1;
      else r = md;
    }
    return l;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  Solution sol;
  int n, target; scanf("%d%d", &n, &target);
  vector<int> nums(n, 0);
  for (int i=0; i<n; ++i) scanf("%d", &nums[i]);
  bool ans = sol.search(nums, target);
  if (ans) printf("YES\n");
  else printf("NO\n");

  return 0;
}
#endif
