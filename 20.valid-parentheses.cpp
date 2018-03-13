#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> mq;
    for (char c : s) {
      if (c == '(' || c == '[' || c == '{') mq.push(c);
      else {
        if (mq.empty()) return false;
        switch (c) {
          case ')':
            if (mq.top() != '(') return false;
            mq.pop();
            break;
          case '}':
            if (mq.top() != '{') return false;
            mq.pop();
            break;
          case ']':
            if (mq.top() != '[') return false;
            mq.pop();
            break;
        }
      }
    }

    return mq.empty();
  }

};
