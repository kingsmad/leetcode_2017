#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> ans(n, 0);
    int p = n - 1;
    for (int i=1; i<n; i+=2) {
      ans[i] = nums.at(p--); 
    }

    for (int i=0; i<n; i+=2) {
      ans[i] = nums.at(p--);
    }

    nums = ans;
    return;
  }
};
