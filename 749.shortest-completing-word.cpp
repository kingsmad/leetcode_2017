#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  string shortestCompletingWord(string licensePlate, vector<string>& words) {
    string s;
    for (char c : licensePlate) {
      if (c >= 'a' && c <= 'z') s.push_back(c);
      if (c >= 'A' && c <= 'Z') s.push_back(c - 'A' + 'a');
    }

    vector<int> ans;
    for (int i = 0; i < words.size(); ++i) {
      const string& p = words.at(i);
      if (check(s, p)) ans.push_back(i);
    }
    sort(ans.begin(), ans.end(), [&](int x, int y) {
      if (words.at(x).size() != words.at(y).size())
        return words.at(x).size() < words.at(y).size();
      return x < y;
    });
    return words.at(ans.front());
  }

  bool check(const string& s, const string& target) {
    multiset<char> ms;
    for (char c : s) ms.insert(c);
    for (char c : target) {
      if (ms.empty()) return true;
      auto it = ms.find(c);
      if (it != ms.end()) ms.erase(it);
    }
    return ms.empty();
  }
};
