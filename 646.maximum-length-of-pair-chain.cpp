#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
      sort(pairs.begin(), pairs.end(), [&](vector<int>& p1, vector<int>& p2) {
          if (p1.at(1) != p2.at(1)) return p1.at(1) < p2.at(1);
          return p1.at(0) < p2.at(0);
      });

      int cnt = 1, lst = pairs.at(0).at(1);
      for (int i=1; i<pairs.size(); ++i) {
        if (pairs[i].at(0) > lst) {
          ++cnt;
          lst = pairs[i].at(1);
        }
      }

      return cnt;
    }
};
