#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return vector<int>();
    sort(nums.begin(), nums.end());
    vector<int> dp(n+1, -1);
    vector<vector<int> > sid2seq(n+1, vector<int>());
  
    dp[0] = 1;
    sid2seq[0].push_back(0);

    for (int i=1; i<n; ++i) {
      int x = -1, v = 1;
      sid2seq[i] = {i};

      for (int j=0; j<i; ++j) {
        if (nums.at(j) != 0 && nums.at(i) % nums.at(j) == 0 && dp[j] + 1 > v) { 
          x = j, v = dp[j] + 1;
        }
      }

      if (x != -1) {
        sid2seq[i] = vector<int>(sid2seq[x].begin(), sid2seq[x].end());
        sid2seq[i].push_back(i);
      }
      dp[i] = v;
    }

    int x = 0; for (int i=0; i<n; ++i) if (dp[i] > dp[x]) x = i;
    
    vector<int> ans;
    for (int d : sid2seq.at(x)) ans.push_back(nums.at(d));
    for (int d : nums) if (d == 0) ans.push_back(0); else break;

    return ans;
  }
};
