#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int calculate(string s) {
    istringstream ss(s); 
    return calc(ss);
  }

  int calc(istringstream& ss) {
    int ans = 0; 
    bool sig = true;
    while(ss.peek() != EOF) {
      if (ss.peek() == ' ') { ss.get(); continue;}
      if (ss.peek() == '+') {
        ss.get();
        sig = true;
      } else if (ss.peek() == '-') {
        ss.get();
        sig = false;
      } else if (ss.peek() == '(') {
        ss.get();
        if (sig) ans = ans + calc(ss);
        else ans = ans - calc(ss);
      } else if (ss.peek() == ')') {
        ss.get();
        break;
      } else {
        int d; ss >> d;
        if (sig) ans += d;
        else ans -= d;
      }
    }

    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int , char**) {
  //string str = "1 + 1";
  string str = " 2-1 + 2 ";
  str = "(1+(4+5+2)-3)+(6+8)";
  Solution sol;
  int ans = sol.calculate(str);
  printf("%d\n", ans);
  return 0;
}
#endif
