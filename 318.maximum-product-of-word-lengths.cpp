#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<string>& words) {
    int n = words.size();
    int ans = 0;
    for (int i=0; i<n; ++i) {
      for (int j=i+1; j<n; ++j) {
        if (Check(words.at(i), words.at(j))) {
          ans = max(ans, (int)words.at(i).size() * (int) words.at(j).size());
        }
      }
    }

    return ans;
  }

  bool Check(const string& s1, const string& s2) {
    vector<bool> b(26, false);
    for (char c : s1) b[c-'a'] = true;

    for (char c : s2) if (b[c-'a']) return false;
    return true;
  }
};
