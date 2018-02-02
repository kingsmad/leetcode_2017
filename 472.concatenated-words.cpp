#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
unordered_set<string> ms;

class Solution {
 public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    ms.clear();
    for (const string& s : words) ms.insert(s);

    vector<string> ans;
    for (const string& s : words) if (s != "" && check(0, s)) ans.push_back(s);
    return ans;
  }

  bool check(int p, string s) {
    int n = s.size();
    if (p == n) return true;
    for (int i=p+1; i<=n; ++i) {
      if (i-p != n && ms.count(s.substr(p, i-p)) && check(i, s)) return true;
    }
    return false;
  }
  
};
