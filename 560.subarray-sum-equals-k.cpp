#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();

    map<int, int> smp;
    smp.emplace(0, 1);

    int sum = 0, ans = 0;
    for (int i=0; i<n; ++i) {
      sum += nums.at(i);
      ans += smp[sum - k];
      ++smp[sum];
    }

    return ans;

  }
};
