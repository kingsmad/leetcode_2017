#include <vector>
#include <string>

using namespace std;

inline int lowbit(int x) { return x & (-x); }

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int n = nums.size();
    vector<int> v1, v2;
    int target = 0;
    for (int d : nums) target ^= d;

    int c = lowbit(target);

    for (int d : nums) {
      if (d & c) v1.push_back(d);
      else v2.push_back(d);
    }
    
    vector<int> ans;
    int p = 0;
    for (int d : v1) p ^= d;
    ans.push_back(p);

    p = 0;
    for (int d : v2) p ^= d;
    ans.push_back(p);


    return ans;
  }

};
