#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    map<string, int> ms; 
    for (int i=0; i<list2.size(); ++i) {
      const string s = list2.at(i);
      if (ms.count(s) > 0) continue;
      ms[s] = i;
    }

    int cnt = INT_MAX;
    for (int i=0; i<list1.size(); ++i) {
      const string s = list1.at(i);
      if (ms.count(s)) {
        cnt = min(cnt, i + ms[s]);
      }
    }

    vector<string> ans;
    for (int i=0; i<list1.size(); ++i) {
      const string s = list1.at(i);
      if (ms.count(s)) {
        if (ms[s] + i == cnt) ans.push_back(s);
      }
    }

    return ans;
  }
};
