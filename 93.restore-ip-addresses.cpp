#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    vector<int> path;
    dfs(0, &path, &ans, s);

    return ans;
  }

  void dfs(int p, vector<int>* path, vector<string>* ans, const string& s) {
    int n = s.size();
    if (path->size() > 4) return;
    if (p == n) {
      if (path->size() != 4) return;
      ans->push_back(Parse(*path));
      return;
    }

    for (int i=1; i<4 && p+i<=n; ++i) {
      int v = ToInt(p, p+i, s);
      if ((s.at(p) != '0' || i==1) && v >= 0 && v < 256) {
        path->push_back(v);
        dfs(p+i, path, ans, s);
        path->pop_back();
      }
    }
  }

  string Parse(const vector<int>& path) {
    string s = "";
    for (int i=0; i<path.size(); ++i) {
      s += to_string(path.at(i));
      s.push_back('.');
    }
    s.pop_back();
    return s;
  }

  int ToInt(int st, int ed, const string& s) {
    int ans = 0;
    for (int i=st; i<ed; ++i) {
      ans = 10 * ans + s.at(i) - '0';
    }
    return ans;
  }
};
