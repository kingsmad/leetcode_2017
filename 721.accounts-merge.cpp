#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 10;

int pa[maxn];
int findset(int x) { return (x == pa[x]) ? pa[x] : (pa[x] = findset(pa[x])); }
void join(int x, int y) { pa[findset(x)] = findset(y); }

class Solution {
 public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    for (int i = 0; i < n; ++i) pa[i] = i;

    vector<set<string>> ms(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < accounts[i].size(); ++j) ms[i].insert(accounts[i][j]);
    }

    for (int i = 0; i < n; ++i)
      for (int j = i+1; j < n; ++j) {
        for (const string& s : ms[i]) {
          if (ms[j].count(s)) {
            join(i, j);
            break;
          }
        }
      }

    for (int i=0; i<n; ++i) {
      int cc = findset(i);
      ms[cc].insert(ms[i].begin(), ms[i].end());
    }

    
    vector<vector<string>> ans;
    for (int i=0; i<n; ++i) {
      if (i != findset(i)) continue;

      vector<string> tmp;
      tmp.push_back(accounts[i].front());
      tmp.insert(tmp.end(), ms[i].begin(), ms[i].end());

      ans.emplace_back(tmp);
    }

    return ans;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  vector<vector<string>> accounts = {
      {"John", "john_newyork@mail.com", "johnsmith@mail.com"},
      {"John", "john00@mail.com", "johnsmith@mail.com"},
      {"Mary", "mary@mail.com"},
      {"John", "johnnybravo@mail.com"}};

  Solution sol;
  const vector<vector<string>> ans = sol.accountsMerge(accounts);

  for (const vector<string>& vec : ans) {
    for (const string& s : vec) cout << s << " ";
    cout << endl;
  }
  return 0;
}
#endif
