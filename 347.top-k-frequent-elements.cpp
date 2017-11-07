#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    set<int> ms;
    map<int, int> smp;
    for (int d : nums) { ms.insert(d); ++smp[d];} 
   
    vector<int> vc(ms.begin(), ms.end());
    auto fn = [&](int x, int y) { return smp.at(x) > smp.at(y); };

    sort(vc.begin(), vc.end(), fn);
    return vector<int>(vc.begin(), vc.begin()+k);
  }
};
