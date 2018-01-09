#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int k = n / 3;

    vector<int> ans;
    for (int i=0; i<n; ) {
      int q = i + 1;
      while(q < n && nums.at(q) == nums.at(i)) ++q;
      if (q - i > k) ans.push_back(nums.at(i)); 
      i = q;
    }

    return ans;
  }
};
