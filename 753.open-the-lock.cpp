#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int rs[2] = { 1, -1};

set<string> ms;
set<string> vis;
map<string, int> s2lv;

class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    ms.clear();
    vis.clear();
    s2lv.clear();

    for (const string& s : deadends) ms.insert(s);
    queue<string> mq;
    if (ms.count("0000") > 0) return -1;
    mq.push("0000");
    s2lv["0000"] = 0;

    while(1) {
      if (mq.empty()) return -1;
      const string& s = mq.front();
      if (s == target) return s2lv[s];
      for (int i=0; i<4; ++i) {
        for (int z=0; z<2; ++z) {
          string t = s;
          t[i] = (t[i] - '0' + rs[z] + 10) % 10 + '0';
          if (vis.count(t) == 0 && ms.count(t) == 0) {
            vis.insert(t);
            mq.push(t);
            if (s2lv.count(t) == 0) s2lv.emplace(t, 0);
            s2lv[t] = s2lv[s] + 1;
          }
        }
      }
      mq.pop();
    }
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  int n; cin >> n;
  vector<string> deadends(n, "");
  for (int i=0; i<n; ++i) cin >> deadends[i];
  string target; cin >> target;

  Solution sol;
  int ans = sol.openLock(deadends, target);
  cout << ans << endl;

  return 0;
}
#endif
