#include <bits/stdc++.h>
using namespace std;
const int maxnode = 1e5 + 10;
const int sigma_sz = 26;
struct Trie {
  int ch[maxnode][sigma_sz], val[maxnode], sz;
  void init() {
    memset(ch, 0, sizeof(ch));
    memset(val, 0, sizeof(val));
    sz = 1;
  }

  void insert(const string& s) {
    int u = 0;
    for (char c : s) {
      int x = c - 'a';
      if (ch[u][x] == 0) ch[u][x] = sz++;
      u = ch[u][x];
    }
    val[u] = 1;
  }

  vector<string> query(const string& s) {
    int u = 0;
    vector<string> ans;
    for (char c : s) {
      int x = c - 'a';
      u = ch[u][x];
      if (u == 0) return ans;
    }
    string path;
    dfs(u, path, ans, s);
    return ans;
  }

  void dfs(int u, string& path, vector<string>& ans, const string s) {
    if (val[u]) ans.push_back(s + path);
    for (int i=0; i<sigma_sz; ++i) {
      if (!ch[u][i]) continue;
      path.push_back(i+'a');
      dfs(ch[u][i], path, ans, s);
      path.pop_back();
    }
  }
} trie;

class Solution {
  vector<vector<string>> ans;
  int dep;

 public:
  vector<vector<string>> wordSquares(vector<string>& words) {
    dep = words.at(0).size();
    trie.init();
    for (const string& s : words) trie.insert(s);

    ans.clear();
    vector<string> path;

    for (const string& s : words) {
      path.push_back(s);

      dfs(path);
      
      path.pop_back();
    }

    return ans;
  }

  void dfs(vector<string>& path) {
    if (path.size() == dep) {
      ans.push_back(path);
      return;
    }

    string prefix;
    int p = path.size();
    for (const string& s : path) { prefix.push_back(s.at(p)); }

    vector<string> cvec = trie.query(prefix);
    for (const string& s : cvec) {
      path.push_back(s);

      dfs(path);

      path.pop_back();
    }
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  // vector<string> words = {"area", "lead", "wall", "lady", "ball"};
  vector<string> words = {"abat","baba","atan","atal"};
  Solution sol;
  vector<vector<string>> ans = sol.wordSquares(words);
  for (const vector<string>& vec : ans) {
    for (const string& s : vec) { cout << s << endl; }
    cout << endl << endl;
  }
  return 0;
}
#endif
