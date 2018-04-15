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
    int tn = n, offset = 0;
    while(n) {
      if (len > 0) {
        int cnt = min(len, n);
        memcpy(buf+offset, b, cnt);
        st += cnt;
        len -= cnt;
        n -= cnt;
        offset += cnt;
      } else {
        st = 0;
        len += read4(b);
        if (len == 0) break;
      }
    }
    return tn - n;
  }
};
