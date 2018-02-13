#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  string reorganizeString(string S) {
    vector<int> cnt(26, 0);
    for (char c : S) ++cnt[c - 'a'];

    string ans = "";
    while(1) {
      int x = -1;
      char c = ans.empty() ? 'A' : ans.back();
      for (int i=0; i<26; ++i) {
        if (i + 'a' != c && cnt[i] > 0) {
          if (x == -1 || cnt[i] > cnt[x]) x = i; 
        }
      }
      if (x == -1) break;
      --cnt[x];
      ans.push_back(x + 'a');
    }

    if (S.size() == ans.size()) return ans;
    return "";
  }
};
