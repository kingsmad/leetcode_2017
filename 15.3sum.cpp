#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

struct Tripple {
  int x, y, z; 
  Tripple(int d1, int d2, int d3) {
    int b[3]; b[0] = d1, b[1] = d2, b[2] = d3;
    sort(b, b+3);
    x = b[0], y = b[1], z = b[2];
  }
};

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();   
    auto fn = [](const Tripple& p, const Tripple& q) {
      if (p.x != q.x) return p.x < q.x;
      if (p.y != q.y) return p.y < q.y;
      return p.z < q.z;
    };
    set<Tripple, decltype(fn)> ans(fn);

    map<int, int> smp;
    for (int i=0; i<n; ++i) ++smp[nums.at(i)];

    for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
      int target = -nums[i] - nums[j];      
      if (smp.count(target) == 0) continue;

      int used = 0;
      if (nums.at(i) == target) ++used;
      if (nums.at(j) == target) ++used;
      if (used >= smp.at(target)) continue;

      ans.insert(Tripple(nums.at(i), nums.at(j), target));
    }

    vector<vector<int>> res;
    for(const Tripple& t : ans) {
      res.push_back({t.x, t.y, t.z});
    }

    return res;
  }
};
