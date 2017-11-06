#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    vector<int> ans;
    for (int d : nums) ans.push_back(f(d, a, b, c));

    sort(ans.begin(), ans.end());
    return ans;
  }

  inline int f(int x, int a, int b, int c) {
    return a * x * x + b * x + c;
  }
};
