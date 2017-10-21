#include <set>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool splitArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> sum(n, 0);

    sum[0] = nums[0];
    for (int i=1; i<n; ++i) sum[i] = sum[i-1] + nums[i];
    
    for(int j=1; j<n; ++j) {
      set<int> v1;
      for (int i=1; i<j; ++i) {
        if (sum[i-1] == sum[j-1] - sum[i]) {
          v1.insert(sum[i-1]);
        }
      }

      if (v1.empty()) continue;

      for (int k=j; k<n; ++k) {
        if (sum[k-1] - sum[j] == sum[n-1] - sum[k]) {
          if (v1.count(sum[k-1] - sum[j]) > 0) return true;
        }
      }
    }

    return false;
  }
};
