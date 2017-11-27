#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  string multiply(string num1, string num2) {
    reverse(num1.begin(), num1.end());      
    reverse(num2.begin(), num2.end());

    string ans;
    for (int i=0; i<num2.size(); ++i) {
      int v = num2.at(i) - '0';
      string s = multiply(num1, v, i);
      ans = add(ans, s);
    }
    
    while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());

    return ans;
  }

  string multiply(const string s, int k, int padding_cnt) {
    string ans(padding_cnt, '0');
    int carry = 0, p = 0;
    while(carry || p < s.size()) {
      int v = 0;
      if (p < s.size()) v += k * (s.at(p++) - '0');
      if (carry) { v += carry; carry = 0;}
      if (v >= 10) {
        carry = v / 10;
        v = v % 10;
      }
      ans.push_back(v + '0');
    }
    return ans;
  }

  string add(const string s1, const string s2) {
    string ans;
    int carry = 0, p = 0, q = 0;
    while(carry || p < s1.size() || q < s2.size()) {
      int v = 0;
      if (p < s1.size()) v += s1.at(p++) - '0';
      if (q < s2.size()) v += s2.at(q++) - '0';
      if (carry) { v += carry; carry = 0;}
      if (v >= 10) {
        v = v - 10;
        carry = 1;
      }
      ans.push_back(v + '0');
    }

    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  string s1, s2; cin >> s1 >> s2;
  Solution sol;
  string ans = sol.multiply(s1, s2);
  cout << ans << endl;
  return 0;
}
#endif
