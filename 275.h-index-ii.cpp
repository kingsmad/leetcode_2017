#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    if (check(n, citations)) return n;
    int l = 0, r = n;
    while(l < r) {
      int md = (l+r) / 2;
      if (check(md, citations)) l = md + 1;
      else r = md;
    }
    return l - 1;
  }

  bool check(int x, vector<int>& nums) {
    int n = nums.size();
    if (n -x >= 0 && n-x < n && nums.at(n-x) < x) return false;
    //if (n-x-1 >= 0 && n-x-1 < n && nums.at(n-x-1) > x ) return false;
    return true;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  vector<int> nums = {0, 1, 3, 5, 6};
  Solution sol;
  int ans = sol.hIndex(nums);
  printf("%d\n", ans);
  return 0;
}
#endif
