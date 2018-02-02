#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
unordered_set<string> dict;
unordered_map<string, vector<string>> ms;

class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    ms.clear(); 
    dict.clear();
    for (const string& s : wordDict) dict.insert(s);
    return wordBreak(s);
  }

  vector<string> wordBreak(const string s) {
    if (ms.count(s) > 0) return ms[s]; 
    vector<string> ans;
    if (dict.count(s) > 0) ans.push_back(s);

    int n = s.size();

    for (int i=1; i<n; ++i) {
      const string w = s.substr(i); 
      if (dict.count(w) > 0) {
        vector<string> vs = wordBreak(s.substr(0, i));
        for (const string& t : vs) {
          ans.push_back(t + " " + w);
        }
      }
    }
    return ms[s] = ans;
  }

  
};
