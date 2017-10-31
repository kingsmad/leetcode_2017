#include <map>
#include <set>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    map<int, int> smp;
    smp.emplace(0, 0);

    int ans = 0, sum = 0;
    for (int i=1; i<=n; ++i) {
      sum = sum + ((nums.at(i-1) == 1) ? 1 : -1);
      if (smp.count(sum) > 0) ans = max(ans, i - smp.at(sum));
      else smp.emplace(sum, i);
    }

    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  int n; scanf("%d", &n);
  vector<int> nums;
  for (int i=0; i<n; ++i) { int d; scanf("%d", &d); nums.push_back(d);}
  
  Solution sol;
  int ans = sol.findMaxLength(nums);
  
  return 0 * printf("%d", ans);

}
#endif
