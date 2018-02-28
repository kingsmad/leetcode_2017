#include <bits/stdc++.h>
using namespace std;
// Forward declaration of the read4 API.
int read4(char* buf);

class Solution {
  char b[4];
  int st = 0, len = 0;

 public:
  /**
   * @param buf Destination buffer
   * @param n   Maximum number of characters to read
   * @return    The number of characters read
   */
  int read(char* buf, int n) {
    int offset = 0;
    int tn = n;
    while (n) {
      if (len > 0) {
        int cnt = min(n, len);
        memcpy(buf+offset, b + st, cnt);
        st += cnt;
        n -= cnt;
        offset += cnt;
        len -= cnt;
      } else {
        st = 0;
        len += read4(b); 
        if (len == 0) break;
      }
    }
    return tn - n;
  }
};
