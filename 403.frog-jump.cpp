#include <set>
#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canCross(vector<int>& stones) {
    map<int, set<int> > ms;
    int n = stones.size();
    for (int i=0; i<n; ++i) {
      ms.emplace(stones[i], set<int>());
    }

    ms[stones[0]].insert(0);

    for (int i=0; i<n; ++i) {
      for (int d : ms[stones[i]]) {
        for (int s=d-1; s<=d+1; ++s) {
          if (s > 0 && ms.count(stones.at(i)+s)) {
            ms[stones.at(i)+s].insert(s);
          }
        }
      }
    }

    return !ms[stones.at(n-1)].empty();
  }
};
