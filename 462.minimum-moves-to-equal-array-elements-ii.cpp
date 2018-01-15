#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

using ll = long long;
class Solution {
public:
  int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int tv = nums.at(n/2);
    int ans = 0;
    for (int d : nums) ans += abs(d - tv);

    return ans;
  }
};
