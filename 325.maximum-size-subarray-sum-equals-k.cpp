#include <vector>
#include <stack>
#include <map>

using namespace std;

class Solution {
  map<int, int> smp;
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    smp.emplace(0, 0);
    int sum = 0, n = nums.size(), ans = 0;
    for (int i=0; i<n; ) {
      sum += nums.at(i++);
      int target = sum - k;
      if (smp.count(target) > 0) {
        ans = max(ans, i - smp.at(target));
      } 
      if (smp.count(sum) == 0) smp.emplace(sum, i);
    }

    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  Solution sol;
  int n; scanf("%d",  &n);

  vector<int> nums; 
  for (int i=0; i<n; ++i) { int d; scanf("%d", &d); nums.push_back(d);}
  int k; scanf("%d", &k);

  int ans = sol.maxSubArrayLen(nums, k);

  return 0 * printf("%d\n", ans);
}
#endif
