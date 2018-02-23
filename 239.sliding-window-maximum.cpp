#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> mq;
    for(int i=0; i<nums.size(); ++i) {
      while(mq.size() && mq.front() <= i-k) mq.pop_front();
      while(mq.size() && nums.at(mq.back()) < nums.at(i)) mq.pop_back(); 
      mq.push_back(i);
      if (i >= k-1) ans.push_back(nums.at(mq.front()));
    }

    return ans;
  }
};
