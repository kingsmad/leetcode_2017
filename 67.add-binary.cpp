#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int carry = 0;
    string c = "";
    int p = 0, q = 0, n1 = a.size(), n2 = b.size();
    while(p < n1 || q < n2 || carry) {
      int v = 0;
      if (p < n1) v += a[p++] - '0';
      if (q < n2) v += b[q++] - '0';
      if (carry) { v += carry; carry = 0;}

      if (v >= 2) { carry = 1; v -= 2;}
      c.push_back(v + '0'); 
    }

    reverse(c.begin(), c.end());
    return c;
  }
};
