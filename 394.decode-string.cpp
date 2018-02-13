#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string decodeString(string s) {
    int n = s.size();
    if (s == "") return "";

    int p = 0;
    while(p < n && s[p] != '[') ++p;
    if (p == n) return s;

    int lcnt = 1, q = p + 1;
    while(lcnt) {
      if (s[q] == '[') ++lcnt;
      else if (s[q] == ']') --lcnt;
      ++q;
    }
    --q;
    assert(s[q] == ']');

    const string s1 = decodeString(s.substr(p+1, q-p-1));
    const string s2 = decodeString(s.substr(q+1, s.size()));  

    string ans;
    int num = 0;
    for (int i=0; i<p; ++i) {
      if (isdigit(s[i])) num = 10 * num + s[i] - '0';
      else ans.push_back(s[i]);
    }

    while(num--) ans += s1;
    ans += s2;
    
    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  Solution sol;
  string str; cin >> str;
  string ans = sol.decodeString(str);
  cout << ans << endl;
  return 0;
}
#endif
