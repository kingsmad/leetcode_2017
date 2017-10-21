#include <string>
#include <vector>

using namespace std;
using ll = long long;

char s[1000];

class Solution {
 public:
  string optimalDivision(vector<int>& nums) {
    string ans = to_string(nums.at(0));
    if (nums.size() > 1) ans.push_back('/');
    if (nums.size() > 2) {
      ans.push_back('(');
    }
    for (int i=1; i<nums.size(); ++i) {
      ans += to_string(nums.at(i));
      if (i+1 != nums.size()) ans += "/";
    }
    if (nums.size() > 2) {
      ans.push_back(')');
    }
    return ans;
  }
};
