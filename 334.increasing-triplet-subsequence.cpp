// Mark
#include <set>
#include <map>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int d1 = INT_MAX, d2 = INT_MAX;
    for (int v : nums) {
      if (v <= d1) d1 = v;
      else if (v <= d2) d2 = v;
      else return true;
    }

    return false;
  }
};
