#include <climits>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

using ll = long long;

class Solution {
 public:
  int nextGreaterElement(int n) {
    char s[40];
    sprintf(s, "%d", n);
    int len = strlen(s);

    int p = len - 1;
    while(p > 0 && s[p-1] >= s[p]) --p;
    if (p == 0) return -1;

    int x = p;
    for (int i=p; i<len; ++i) {
      if (s[i] > s[p-1] && s[i] < s[x]) x = i;
    }

    swap(s[p-1], s[x]);
    sort(s+p, s+len);

    ll ans = 0; 
    sscanf(s, "%lld", &ans);

    if (ans > INT_MAX) return -1;
    return ans;
  }
};
