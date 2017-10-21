#include <vector>
using namespace std;
const int maxn = 5e4 + 10;

int sum[maxn];

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    sum[0] = nums.at(0);
    for (int i=1; i<n; ++i) sum[i] = sum[i-1] + (nums.at(i) == 1);

     
  }
};
