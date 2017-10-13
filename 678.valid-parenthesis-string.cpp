// Kingsmad Mark
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool checkValidString(string s) {
    int mi = 0, ma = 0; 
    for (char c : s) {
      if (c == '(') ++mi; else --mi;
      if (c != ')') ++ma; else --ma;
      if (ma < 0) return false;
      mi = max(0, mi);
    }

    return mi == 0;
  }
};
