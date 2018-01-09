#include <climits>
#include <vector>

using namespace std;
int n;

class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    n = nums.size();
    int ans = n + 1;

    int sum = 0, p = 0, q = 0;
    for (int i=0; i<n; ++i) {
      while(p < i) sum -= nums.at(p++);
      while(q < n && sum < s) sum += nums.at(q++); 
      if (q == n && sum < s) break;
      ans = min(ans, q - i);
    }

    if (ans == n+1) ans = 0;
    return ans;
  }
};
