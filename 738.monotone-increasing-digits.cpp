#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int monotoneIncreasingDigits(int N) {
    char s[100];
    sprintf(s, "%d", N);
    int n = strlen(s);

    int p = 0;
    while(p+1 < n && s[p] <= s[p+1]) ++p;
    while(p > 0 && s[p-1] == s[p]) --p;
    if (p == n-1) return N;
    --s[p];
    for (int i=p+1; i<n; ++i) s[i] = '9'; 

    int d; sscanf(s, "%d", &d);
    return d;
  }
};
