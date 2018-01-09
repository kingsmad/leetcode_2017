#include <algorithm>
#include <list>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    int n = people.size();
    list<pair<int, int>> mlist;
    sort(people.begin(), people.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first != p2.first) return p1.first > p2.first;
        return p1.second < p2.second;
    });

    for (int i=0; i<n; ++i) {
      auto it = mlist.begin();
      int cnt = people.at(i).second;
      while(cnt--) ++it;
      mlist.insert(it, people.at(i));
    }

    return vector<pair<int, int> > (mlist.begin(), mlist.end());
  }
};
