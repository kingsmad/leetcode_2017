#include <algorithm>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
 public:
  const string Cut(int wid, int cc, bool rev, vector<string>& strs) {
    string ans = "";
    string tmp = strs.at(wid);
    if (rev) reverse(tmp.begin(), tmp.end());

    ans = tmp.substr(cc, tmp.size());
    const string rem = tmp.substr(0, cc);
    
    for (int i=1; i<strs.size(); ++i) {
      ans += strs.at((wid + i) % strs.size()); 
    }

    ans += rem;

    return ans;
  }

  string splitLoopedString(vector<string>& strs) {
    for (string& s : strs) {
      string t = s;
      reverse(t.begin(), t.end());
      s = max(s, t);
    }

    string ans = "a";
    for (int wid=0; wid<strs.size(); ++wid) {
      for (int cc=0; cc<strs.at(wid).size(); ++cc) {
        ans = max(ans, Cut(wid, cc, false, strs));
        ans = max(ans, Cut(wid, cc, true, strs));
      }
    }

    return ans;
  }
};
