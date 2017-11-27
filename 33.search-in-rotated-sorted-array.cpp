#include <vector>
#include <algorithm>
// Mark, line 32: use pivot

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return -1;

    int p = FindStart(nums);
    //printf("%d\n", p);

    int l = p, len = n;
    while(len > 0) {
      int md = (l + len / 2) % n;
      if (nums.at(md) == target) return md;
      if (nums.at(md) < target) { l = md + 1; len = len - len / 2 - 1;}
      else { len = len / 2;}
    }

    return -1;
  }

  int FindStart(const vector<int>& nums) {
    int n = nums.size();
    if (nums.at(0) < nums.at(n-1)) return 0;

    int l = 0, r = n;
    int pv = nums.at(0);
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
  int n; scanf("%d", &n);
  vector<int> nums;
  while(n--) { int d; scanf("%d", &d); nums.push_back(d); }
  int target; scanf("%d", &target);

  Solution sol;
  int ans = sol.search(nums, target);
  return 0 * printf("%d\n", ans);
}
#endif
