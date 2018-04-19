#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool validWordAbbreviation(string word, string abbr) {
    int p = 0;
    for (int i = 0; i < abbr.size();) {
      if (!isdigit(abbr[i])) {
        if (abbr[i] != word[p]) return false;
        ++i, ++p;
        continue;
      }
      if (abbr[i] == '0') return false;
      int q = i + 1;
      while(q < abbr.size() && isdigit(abbr[q])) ++q;
      p += stoi(abbr.substr(i, q-i)); 
      i = q;
    }
    return p == word.size();
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  Solution sol;
  bool ans = sol.validWordAbbreviation("internationalization", "i12iz4n");
  if (ans) printf("YES\n");
  else printf("no\n");
  return 0;
}
#endif
