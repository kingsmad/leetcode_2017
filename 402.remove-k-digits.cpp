#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <deque>

using namespace std;

class Solution {
 public:
  string removeKdigits(string num, int k) {
    deque<char> deq;
    for (char c : num) {
      if (deq.empty()) {
        if (c != '0') deq.push_back(c);
      } else {
        char x = deq.back();
        if (c >= x) { deq.push_back(c); continue;}
        while(!deq.empty() && deq.back() > c && k > 0) {
          deq.pop_back();
          --k;
        }
        if (!deq.empty() || c != '0') deq.push_back(c);
      }
    }

    while(k > 0 && !deq.empty()) { deq.pop_back(); --k;}

    if (deq.empty()) return "0";
    return string(deq.begin(), deq.end());
  }
};

#ifdef ROACH_ONLINE_JUDGE

int main(int argc, char** argv) {
  string s; cin >> s;
  int k; cin >> k;
  Solution sol;
  string ans = sol.removeKdigits(s, k);
  cout << ans << endl;
  return 0;
}

#endif
