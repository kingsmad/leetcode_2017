#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int jump(vector<int>& nums) {
    int n = nums.size();    
    queue<pair<int, int>> mq;
    mq.push({0, 0});
    int pv = 1;

    while(mq.size()) {
      int x = mq.front().first, y = mq.front().second;
      mq.pop();
      if (x == n-1) return y;
      for (int i=pv; i<=min(n-1, x+nums[x]); ++i) {
        mq.push({i, y+1});  
      }
      pv = x + nums[x] + 1;
    }
    return -1;
  }
};
