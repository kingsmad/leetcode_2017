#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;

int n, G[maxn][maxn], c[maxn];
vector<int> topo;
void init(int tn) {
  n = tn;
  memset(G, 0, sizeof(G));
}

void AddEdge(int x, int y) {
  G[x][y] = 1;
}

bool dfs(int u) {
  c[u] = -1; 
  for (int i=0; i<n; ++i) if (G[u][i]) {
    if (c[i] < 0) return false;
    else if (c[i] == 0 && !dfs(i)) return false;
  }

  topo.push_back(u);
  c[u] = 1;
  return true;
}

bool toposort() {
  memset(c, 0, sizeof(c)); 
  topo.clear();
  for (int i=0; i<n; ++i) {
    if (c[i] == 0 && !dfs(i)) return false;
  }
  reverse(topo.begin(), topo.end());
  return true;
}

class Solution {
 public:
  string alienOrder(vector<string>& words) {
    init(26);    
    for (int i=0; i+1<words.size(); ++i) {
      Proc(words.at(i), words.at(i+1)); 
    }

    if (!toposort()) return "";

    set<char> chs;
    for (const string& s : words) for (char c : s) chs.insert(c);
    string ans = "";
    for (int d : topo) {
      if (chs.count(d+'a') == 0) continue;
      ans += d + 'a';
    }
    return ans;
  }

  void Proc(const string& s1, const string& s2) {
    int n1 = s1.size(), n2 = s2.size(); 
    for (int i=0; i<min(n1, n2); ++i) {
      if (s1.at(i) != s2.at(i)) { 
        AddEdge(s1.at(i) - 'a', s2.at(i) - 'a');      
        return;
      } 
    }
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int, char**) {
  Solution sol;
  vector<string> words = {"wrt","wrf","er","ett","rftt"};
  string ans = sol.alienOrder(words);
  cout << ans << endl;
  return 0;
}
#endif
