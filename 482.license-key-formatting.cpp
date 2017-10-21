#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string licenseKeyFormatting(string S, int K) {
    int n = S.size();
    for (char c : S) n -= (c=='-');

    int prefix = n % K;
    if (prefix == 0) prefix = K;

    string ans = "";
    int pos = 0, turn = 0, cnt = 0;
    while(pos < S.size()) {
      char c = ToUpper(S.at(pos++)); 
      if (c == '-') continue;

      ans.push_back(c);
      ++cnt;
     
      int Gap = (turn > 0) ? K : prefix;
      if (cnt == Gap) { cnt = 0; ans.push_back('-'); ++turn;}
    }

    if (ans.back() == '-') ans.pop_back();
    return ans;
  }

  char ToUpper(char c) {
    if (c <= 'z' && c >= 'a') return 'A' + (c - 'a');
    else return c;
  }
};
