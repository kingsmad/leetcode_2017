#include <string>
#include <vector>
using namespace std;


class Solution {
 public:
  string simplifyPath(string path) {
    int n = path.size();
    string ans = "";
    for (int i=0; i<n; ) {
      while(i < n && path.at(i) == '/') ++i;
      if (i == n) break;
      int q = i + 1;
      while(q<n && path.at(q) != '/') ++q;

      const string str = path.substr(i, q-i);
      if (str == "..") {
        while(!ans.empty() && ans.back() != '/') ans.pop_back();
        if (!ans.empty() && ans.back() == '/') ans.pop_back();
      } else if (str == ".") {
        
      } else {
        ans.push_back('/');
        ans += str;
      }

      i = q;
    }

    if (ans == "") ans = "/";
    return ans;
  }
};
