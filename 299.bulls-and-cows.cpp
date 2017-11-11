#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string getHint(string secret, string guess) {
    int n = secret.size();
    int cnt = 0;
    for (int i=0; i<n; ++i) if (secret.at(i) == guess.at(i)) { 
      secret[i] = guess[i] = '-'; 
      ++cnt;
    }

    int acnt = 0;
    vector<int> hs(26, 0);

    for (char c : secret) if (c != '-') ++hs[c - '0'];

    for (char c : guess) if (c != '-' && hs[c-'0'] > 0) {
      ++acnt;
      --hs[c-'0'];
    }

    return to_string(cnt) + "A" + to_string(acnt) + "B";
  }
};
