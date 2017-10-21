#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string findContestMatch(int n) {
    map<int, string> v2str;
    map<int, string> smp;
    for (int i = 1; i <= n; ++i) v2str.emplace(i, to_string(i));

    int round = 0;
    while (v2str.size() > 1) {
      while(v2str.size() > 1) {
        auto st = v2str.begin(), ed = v2str.end(); --ed;
        string ss = "";
        if (st->first > ed->first || round == 0) 
          ss = "(" + st->second + "," + ed->second + ")";
        else
          ss = "(" + ed->second + "," + st->second + ")";

        int v = max(st->first, ed->first);
        smp.emplace(v, ss);
        v2str.erase(st);
        v2str.erase(ed);
      }
      
      v2str = smp; 
      smp.clear();
      round = 1;
    }

    return v2str.begin()->second;
  }
};
