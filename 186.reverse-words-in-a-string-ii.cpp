#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  void reverseWords(vector<char>& str) {
    int n = str.size();
    int p = 0, q = n -1 ;
    while(p < q ) { swap(str[p], str[q]); ++p, --q;}

    for (int i=0; i<n; ) {
      while(i < n && str[i] == ' ') ++i;
      int q = i + 1;
      while(q < n && str[q] != ' ') ++q;
      int p1 = i, p2 = q - 1;
      while(p1 < p2) {
        swap(str[p1], str[p2]);
        ++p1, --p2;
      }
      i = q;
    }
  }
};
