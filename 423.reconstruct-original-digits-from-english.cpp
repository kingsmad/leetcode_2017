#include <bits/stdc++.h>

using namespace std;

class Solution {
  unordered_map<char, int> ms;
public:
  string originalDigits(string s) {
    ms.clear();
    for (char c : s) ++ms[c];

    string ans;
    while(1) {
      if (ms['x'] > 0) {
        ans.push_back('6');
        for (char c : "six") --ms[c];
        continue;
      }
      if (ms['z'] > 0) {
        ans.push_back('0');
        for (char c : "zero") --ms[c];
        continue;
      }
      if (ms['w'] > 0) {
        ans.push_back('2');
        for (char c  : "two") --ms[c];
        continue;
      }
      if (ms['g'] > 0) {
        ans.push_back('8');
        for (char c : "eight") --ms[c];
        continue;
      }
      if (ms['s'] > 0) {
        ans.push_back('7');
        for (char c : "seven") --ms[c];
        continue;
      }
      if (ms['u'] > 0) {
        ans.push_back('4');
        for (char c : "four") --ms[c];
        continue;
      }
     
      if (ms['f'] > 0) {
        ans.push_back('5');
        for (char c : "five") --ms[c];
        continue;
      }
      if (ms['t'] > 0) {
        ans.push_back('3');
        for (char c  : "three") --ms[c];
        continue;
      }
      if (ms['o'] > 0) {
        ans.push_back('1');
        for (char c : "one") --ms[c];
        continue;
      }
      if (ms['n'] > 0) {
        ans.push_back('9');
        for (char c : "nine") --ms[c];
        continue;
      }
      break; 
    }
    sort(ans.begin(), ans.end());
    return ans;
  }

  
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  string str; cin >> str;
  Solution sol;
  string ans = sol.originalDigits(str);
  cout << ans << endl;
  return 0;
}
#endif
