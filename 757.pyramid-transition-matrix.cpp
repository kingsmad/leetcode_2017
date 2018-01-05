#include <map>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 500;

map<string, vector<char>> ms;
char buf[maxn][maxn];
class Solution {
 public:
  bool pyramidTransition(string bottom, vector<string>& allowed) {
    ms.clear(); 
    int n = bottom.size();
    for (const string& s : allowed) {
      vector<char>& v = ms[s.substr(0, 2)]; 
      v.push_back(s.at(2)); 
    }

    for (int i=0; i<n; ++i) buf[0][i] = bottom.at(i);

    bool done = false;
    dfs(1, 0, n, done);
    return done;
  }

  void dfs(int i, int j, int n, bool& done) {
    if (i == n) {
      done = true; 
      return;
    }

    string base; 
    base.push_back(buf[i-1][j]);
    base.push_back(buf[i-1][j+1]);
    if (ms.count(base) == 0) return;

    const vector<char>& vc = ms.at(base);

    for (char c : vc) {
      buf[i][j] = c;
      if (i+j+1 < n) dfs(i, j+1, n, done);
      else dfs(i+1, 0, n, done);
      if (done) return;
    }
  }
};
