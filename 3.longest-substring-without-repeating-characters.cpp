#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size(), ans = 0;
    unordered_set<char> ms;
    int p = 0, q = 0; 
    while(q < n) {
      if (ms.count(s.at(q)) == 0) {
        ms.insert(s.at(q));
        ++q;
        ans = max(ans, q - p);
        continue;
      } else {
        ms.erase(s.at(p));
        ++p;
      }
    }

    return ans;
  }
};
