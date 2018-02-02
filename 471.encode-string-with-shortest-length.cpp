#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
const int maxn = 200;
map<pair<int, int>, string> dp;

class Solution {
 public:
  string encode(string s) {
    dp.clear();

    return calc(0, s.size(), s);
  }

  const string calc(int p, int q, const string& s) {
    if (p == q) return "";
    if (dp.count(make_pair(p, q)) > 0) return dp.at(make_pair(p, q));

    string ans = s.substr(p, q - p);
    int n = s.size();
    for (int bsz = 1; bsz < n; ++bsz) {
      if ((q - p) % bsz > 0) continue;
      bool check = true;
      for (int i = p; i < p + bsz; ++i) {
        char c = s[i];
        for (int j = i; j < q; j += bsz) {
          if (c != s[j]) {
            check = false;
            break;
          }
        }
        if (!check) break;
      }

      if (check) {
        int cnt = (q - p) / bsz;
        char buf[10];
        sprintf(buf, "%d", cnt);
        if (strlen(buf) + 2 + bsz < q - p) {
          ans = string(buf) + "[" + calc(p, p + bsz, s) + "]";
        }
        break;
      }
    }

    for (int k = p+1; k < q; ++k) {
      const string tmp = calc(p, k, s) + calc(k, q, s);
      if (tmp.size() < ans.size()) { ans = tmp; }
    }

    dp.emplace(make_pair(p, q), ans);
    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  string str;
  cin >> str;
  Solution sol;
  string ans = sol.encode(str);
  cout << ans << endl;
  return 0;
}
#endif
