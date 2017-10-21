#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
 public:
  string complexNumberMultiply(string a, string b) {
    int x1, x2, y1, y2;
    Parse(a, &x1, &y1);
    Parse(b, &x2, &y2);

    int r = x1 * x2 - (y1 * y2), c = x1 * y2 + x2 * y1;
    char buf[100];
    sprintf(buf, "%d+%di", r, c);
    return string(buf);
  }

  void Parse(const string& s, int* x, int* y) {
    sscanf(s.c_str(), "%d+%di", x, y);
  }
};

#ifdef ROACH_ONLINE_JUDGE

int main(int argc, char** argv) {
  
}

#endif
