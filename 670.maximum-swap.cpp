#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;
class Solution {
public:
    int maximumSwap(int num) {
      char s[20];        
      sprintf(s, "%d", num);
      int n = strlen(s);
      
      int p = 0;
      while( p< n) {
        int c = p; 
        for (int i=c; i<n; ++i) {
          if (s[c] <= s[i]) c = i;
        }

        if (s[c] == s[p]) { ++p; continue;}
        
        swap(s[c], s[p]);
        break;
      }

      sscanf(s, "%d", &num);
      return num; 
    }
};


