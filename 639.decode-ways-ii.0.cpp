#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
class Solution {
 public:
  int numDecodings(string s) {
    unordered_map<int, ll> ms;
    return dfs(0, s, ms);
  }

  ll dfs(int p, const string& s, unordered_map<int, ll>& ms) {
    int n = s.size();
    if (p == n) return 1;
    if (s[p] == '0') return 0;
    if (ms.count(p) > 0) return ms.at(p);

    ll v = (s[p] == '*') ? 9 * dfs(p + 1, s, ms) % mod : dfs(p + 1, s, ms);
    if (p + 1 < n) {
      if (s[p] != '*' && s[p + 1] != '*') {
        if (s[p] == '1' || (s[p] == '2' && s[p + 1] < '7'))
          v = (v + dfs(p + 2, s, ms)) % mod;
      } else if (s[p] != '*' && s[p + 1] == '*') {
        if (s[p] == '1') v = (v + 9 * dfs(p + 2, s, ms) % mod) % mod;
        if (s[p] == '2') v = (v + 6 * dfs(p + 2, s, ms) % mod) % mod;
      } else if (s[p] == '*' && s[p + 1] != '*') {
        if (s[p + 1] < '7') v = (v + dfs(p + 2, s, ms)) % mod;
        v = (v + dfs(p + 2, s, ms)) % mod;
      } else {  // both equal '*'
        v = (v + 15 * dfs(p + 2, s, ms)) % mod;
      }
    }
    return ms[p] = v;
  }
};

int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  string s;  cin >> s;
  Solution sol; 
  int ans = sol.numDecodings(s);
  printf("%d\n", ans);
  return 0;
}
