#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> tmp = {1};
    tmp.resize(rowIndex+1, 0);
    for (int n=1; n<=rowIndex; ++n) {
      for (int i=n-1; i>0; --i) {
        tmp[i] = tmp[i] + tmp[i-1];
      }
      tmp[0] = tmp[n] = 1;
    }
    return tmp;
  }
};
