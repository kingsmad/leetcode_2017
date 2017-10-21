#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  void Parse(const string& s, map<string, vector<string>>& smp) {
    int n = s.size();
    int p = 0;
    while (p < n && s.at(p) != ' ') ++p;
    const string srt = s.substr(0, p) + "/";
    while (1) {
      while (p < n && s.at(p) != ' ') ++p;
      if (p == n) break;
      int st = p;
      while (st < n && s.at(st) != '(') ++st;
      int ed = st + 1;
      while (ed < n && s.at(ed) != ')') ++ed;
      const string content = s.substr(st + 1, ed - st - 1);
      if (smp.count(content) == 0) smp.emplace(content, vector<string>());
      const string sn = s.substr(p + 1, st - p - 1);
      smp[content].push_back(srt + sn);
      p = ed + 1;
    }
  }

  vector<vector<string>> findDuplicate(vector<string>& paths) {
    map<string, vector<string>> smp;
    for (const string& s : paths) Parse(s, smp);
    vector<vector<string>> ans;
    for (auto it = smp.begin(); it != smp.end(); ++it) {
      if (it->second.size() > 1) ans.push_back(it->second);
    }
    return ans;
  }
};
