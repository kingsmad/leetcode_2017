#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();      
    vector<string> ans;
    for (int i=0; i<n; ) {
      int q = i + 1;
      while(q < n && nums[q] == nums[q-1] + 1) ++q;
      char b[100];
      if (q > i + 1) {
        sprintf(b, "%d->%d", nums.at(i), nums.at(q-1));
      } else {
        sprintf(b, "%d", nums.at(i)); 
      }
      ans.push_back(string(b));
      i = q;
    }

    return ans;
  }
};
