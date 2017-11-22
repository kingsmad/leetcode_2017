#include <climits>
#include <iostream>
#include <vector>
#include <bitset>


using namespace std;
using ll = long long;

const int maxn = 1e6 + 10;
bitset<maxn> bs;

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int mi = nums.front();
    for (int d : nums) mi = min(mi, d);
    bs.reset();

    for (int d : nums) { 
      if (bs.test(d - mi)) return d;
      bs.set(d-mi);
    }

    return -1;
  }
};
