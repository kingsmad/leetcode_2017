#include <string>
#include <vector>
const int maxn = 1e3 + 10;

using namespace std;
class Solution {
  map<string, int> str2sid;
  int sz = 0;

  int fa[maxn];
  inline int findset(int x) { return x==fa[x] ? x : fa[x] = findset(fa[x]);}
  void join(int x, int y) {
    int u = findset(x), v = findset(y);
    if (u == v) return;
    fa[u] = v;
  }
 public:
  bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2,
                              vector<pair<string, string>> pairs) {
    if (words1.size() != words2.size()) return false;
    init();
    for (auto& p : pairs) {
      join(getsid(p.first), getsid(p.second));
    }

    for (int i=0; i<words1.size(); ++i) {
      if (findset(getsid(words1.at(i))) != findset(getsid(words2.at(i)))) 
        return false;
    }
    return true;
  }

  int getsid(const string& s) {
    if (str2sid.count(s) ) return str2sid.at(s);
    return str2sid[s] = sz++;
  }

  void init() {
    sz = 0;
    str2sid.clear();
    for (int i=0; i<maxn; ++i) fa[i] = i;
  }
};
