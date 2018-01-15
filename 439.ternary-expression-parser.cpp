#include <stack>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  string parseTernary(string expression) {
    stack<char> ms;
    int n = expression.size();
    for (int i=n-1; i>0; --i) {
      char c = expression.at(i);
      if (isdigit(c)) ms.push(c);
      if (c == '?') {
        char x = ms.top();
        ms.pop();
        char y = ms.top();
        ms.pop();

        if (expression.at(i-1) == 'T') ms.push(x); 
        else ms.push(y);
      } 
    }

    string ans = "";
    ans.push_back(ms.top());
    return ans;
  }
};
