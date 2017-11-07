#include <iostream>

#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
  map<string, bool> smp;
 public:
  bool canWin(string s) {
    if (s.size() < 2) return false;
    if (smp.count(s) > 0) return smp.at(s); 
    
    int n = s.size();
    for (int i=0; i+1<n; ++i) {
      if (s[i] == '+' && s[i+1] == '+') {
        if (!canWin(s.substr(0, i) + "--" + s.substr(i+2, n))) {
          return smp[s] = true;
        }
      }
    }
    
    return smp[s] = false;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  string str; cin >> str;
  Solution sol;    
  bool ok = sol.canWin(str);
  if (ok) printf("YES\n");
  else printf("NO\n");

  return 0;
}
#endif
