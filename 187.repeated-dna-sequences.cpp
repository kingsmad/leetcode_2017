#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    int n = s.size();
    unordered_map<string, int> ms;
    for (int i=0; i+10<=n; ++i) {
      string st = s.substr(i, 10);
      if (ms.count(st) == 0) ms.emplace(st, 0);
      ++ms[st];
    }

    vector<string> ans;
    for (auto it: ms) {
      if (it.second > 1) ans.emplace_back(it.first);
    }
    return ans;
  }
};
