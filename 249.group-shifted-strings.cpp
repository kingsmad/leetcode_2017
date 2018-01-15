#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    map<string, vector<string>> ms;
    for (const string& s: strings) {
      string tmp = s;
      char c = tmp.front();
      for (int i=0; i<tmp.size(); ++i) tmp[i] = (tmp[i] + 26 - c) % 26;
      if (ms.count(tmp) == 0) ms.emplace(tmp, vector<string>());
      ms[tmp].push_back(s);
    }

    vector<vector<string>> ans;
    for (const auto& it : ms) {
      ans.push_back(it.second);
    }

    return ans;
  }
};
