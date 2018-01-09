#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> ans;
    if (n < 0) return ans;
    int len = 1 << n;
    for (int i=0; i<len; ++i) {
      ans.push_back(i ^ (i>>1));
    }
    return ans;
  }
};
