#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    map<string, int> ms;
    for (const string& s : words) ++ms[s];

    vector<string> ans;
    for (auto& it: ms) ans.push_back(it.first);

    sort(ans.begin(), ans.end(), [&](const string& s1, const string& s2) {
      if (ms[s1] != ms[s2])
        return ms[s1] > ms[s2];
      else
        return s1 < s2;
    });

    return vector<string>(ans.begin(), ans.begin()+k);
  }
};
