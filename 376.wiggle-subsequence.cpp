#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size(); 
    if (n == 0) return 0;
    int cnt = 0;
    vector<int> ans;
    
    for (int i=1; i+1<n; ++i) {
      if ((nums.at(i) > max(nums.at(i-1), nums.at(i+1))) || 
          nums.at(i) < min(nums.at(i-1), nums.at(i+1))) {
        ans.push_back(nums.at(i));
      }
    }

    if (ans.size() >= 1) return ans.size() + 2;

    if (nums.size() >= 2) {
      if (nums.front() != nums.back()) return 2;
      else return 1;
    }

    return nums.size();
  }

};
