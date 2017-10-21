#include <algorithm>
#include <set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findPermutation(string s) {
    vector<int> ans;
    for (int i=1; i<=s.size()+1; ++i) ans.push_back(i);

    for (int i=0; i<s.size(); ) {
      while(i < s.size() && s.at(i) == 'I') ++i;
      if (i == s.size()) break;
      int q = i + 1;
      while(q < s.size() && s.at(q) == 'D') ++q;
      reverse(ans.begin() + i, ans.begin() + q + 1);
      i = q;
    }

    return ans;
  }
};
