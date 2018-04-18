#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int st = 0, ed = nums.size();
    while(k) {
      k = k % (ed - st);
      for (int i=0; i<k; ++i) swap(nums[st+i], nums[ed-k+i]);
      st += k;
    }
    return;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  vector<int> v = {1,2,3,4,5,6,7};
  Solution sol;
  sol.rotate(v, 3);
  for (int d : v) printf("%d ", d);
  return 0;
}
#endif
