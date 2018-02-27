#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 7;

class Solution {
 public:
  string rearrangeString(string s, int k) {
    int n = s.size();
    if (k == 0) return s;

    map<int, int> ms;
    for (char c : s) ++ms[c-'a'];

    auto fn = [&](int x, int y) {
      if (ms[x] != ms[y]) return ms[x] > ms[y];
      return x < y;
    };
    set<int, decltype(fn)> mq(fn);
    for (const pair<int, int>& pr : ms) mq.insert(pr.first);

    string ans;
    while(1) {
      int t = min(n - (int)ans.size(), k);
      if (t == 0) break;
      if (mq.size() < t) return "";
      vector<int> b;
      auto it = mq.begin();
      while(b.size() < t) b.push_back(*it++);
      for (int d : b) {
        ans.push_back(d + 'a');
        mq.erase(d);
        --ms[d];
        if (ms[d] == 0) ms.erase(d);
        if (ms[d] > 0) mq.insert(d);
      }
    }

    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  // int k;
  // string str; cin >> str >> k;
  string str = "aabbcc";
  int k = 2;
  Solution sol;
  string ans = sol.rearrangeString(str, k);
  cout << ans << endl;
  return 0;
}
#endif
