#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    map<int, int> smp;
    int n = nums.size();
    int p = 0;
    for (int d : nums) {
      if (smp[d] < 2) {
        ++smp[d];
        nums[p++] = d;
      }
    }

    nums.erase(nums.begin() + p, nums.end());
    return p;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  int n; scanf("%d", &n);
  vector<int> nums;
  while(n--) { int d; scanf("%d", &d); nums.push_back(d);}

  Solution sol;
  printf("%d\n", sol.removeDuplicates(nums));
  return 0;
}
#endif
