#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string> > smp;
    for (const string& s : strs) {
      string t = s;
      sort(t.begin(), t.end());
      smp[t].push_back(s);
    }

    vector<vector<string> > ans;
    for (const auto& it : smp) {
      ans.push_back(it.second);
    }

    return ans;

  }

  
};
