#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  void Parse(const string& s, int& st, int& xcnt, int& sum, int rev) {
    int dir = 1; 
    // first char is signal
    if (s[st] == '+' || s[st] == '-') {
      dir = (s[st++] == '+') ? 1 : -1;  
    }
    
    int bug_st = st;
    int v = 0;
    while(isdigit(s[st])) v = 10 * v + s[st++] - '0';
    if (bug_st == st) v = 1;

    if (s[st] == 'x') { xcnt += v * dir * rev; ++st;}
    else sum += dir * v * rev;
  }

  string solveEquation(string equation) {
    int st = 0, xcnt = 0, sum = 0;
    while(equation[st] != '=') Parse(equation, st, xcnt, sum, 1);
    ++st; 
    while(st < equation.size()) Parse(equation, st, xcnt, sum, -1);

    if (xcnt == 0) {
      if (sum == 0) return "Infinite solutions"; 
      else return "No solution";
    }

    int x = - sum / xcnt;
    char buf[100];
    sprintf(buf, "x=%d", x);
    return string(buf);
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  Solution sol;
  string str; cin >> str;
  string ans = sol.solveEquation(str);
  cout << ans << endl;
}

#endif
