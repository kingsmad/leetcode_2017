#include <bits/stdc++.h>
using namespace std;
class ValidWordAbbr {
  map<string, int> ms;
  set<string> oms;

 public:
  ValidWordAbbr(vector<string> dictionary) {
    ms.clear();
    set<string> dic(dictionary.begin(), dictionary.end());
    for (const string& s : dic) {
      oms.insert(s);
      ++ms[calc(s)];
    }
  }

  bool isUnique(string word) {
    const string t = calc(word);
    if (ms.count(t) == 0) return true;
    if (oms.count(word) > 0) return ms[t] == 1;
    else return ms[t] == 0;
  }

  const string calc(const string s) {
    if (s.size() < 2) return s;
    string tmp;
    tmp.push_back(s.front());
    tmp += to_string(s.size() - 2);
    tmp.push_back(s.back());
    return tmp;
  }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
