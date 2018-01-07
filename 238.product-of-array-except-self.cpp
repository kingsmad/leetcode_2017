#include <vector>
#include <string>

using namespace std;
using ll = long long;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    ll sum = nums.at(0);
    vector<int> ans(1, 1);
    for (int i=1; i<n; ++i) {
      ans.push_back(sum);
      sum *= nums.at(i);
    }

    sum = nums.at(n-1);
    for (int i=n-2; i>=0; --i) {
      ans[i] *= sum;
      sum *= nums.at(i);
    }

    return ans;
  }
};
