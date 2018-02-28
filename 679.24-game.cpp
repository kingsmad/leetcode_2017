#include <bits/stdc++.h>
using namespace std;
const double epi = 1e-6;
bool eq(double x, double y) { return fabs(x - y) < epi; }

class Solution {
 public:
  bool judgePoint24(vector<int>& nums) {
    vector<double> ms(nums.begin(), nums.end());
    return dfs(ms);
  }

  bool dfs(vector<double>& ms) {
    if (ms.empty()) return false;
    if (ms.size() == 1) return eq(ms.front(), 24);

    int n = ms.size();
    for (int i=0; i<n; ++i) {
      for (int j=i+1; j<n; ++j) {
        vector<double> cur_res = combine(ms[i], ms[j]); 
        for (double d : cur_res) {
          vector<double> ns(1, d);
          for (int z=0; z<n; ++z) if (z != i && z != j) {
            ns.push_back(ms[z]);
          }
          if (dfs(ns)) return true;
        }
      }
    }

    return false;
  }

  vector<double> combine(double x, double y) {
    vector<double> ans; 
    ans.push_back(x + y);
    ans.push_back(x - y);
    ans.push_back(y - x);
    ans.push_back(x * y);
    if (!eq(y, 0)) ans.push_back(x / y);
    if (!eq(x, 0)) ans.push_back(y / x);
    return ans;
  }

};
