#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

class Solution {
 public:
   ll Dis(const vector<int>& p1, const vector<int>& p2) {
     ll x = p1.at(0) - p2.at(0), y = p1.at(1) - p2.at(1);
     return x * x + y * y;
   }
  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                   vector<int>& p4) {
    map<ll, int> mmp;
    mmp[Dis(p1, p2)] += 1;
    mmp[Dis(p1, p3)] += 1;
    mmp[Dis(p1, p4)] += 1;
    mmp[Dis(p2, p3)] += 1;
    mmp[Dis(p2, p4)] += 1;
    mmp[Dis(p4, p3)] += 1;

    if (mmp.size() != 2) return false;
    vector<int> ans;
    for (auto it=mmp.begin(); it!=mmp.end(); ++it) {
      ans.push_back(it->second);
    }

    sort(ans.begin(), ans.end());
    if (ans.at(0) != 2 || ans.at(1) != 4) return false;
    return true;
  }
};
