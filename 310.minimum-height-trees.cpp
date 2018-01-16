#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;
map<int, set<int> > ms;

class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    if (edges.empty()) return {0};
    ms.clear();
    for (auto p : edges) {
      int u = p.first, v = p.second;
      if (ms.count(u) == 0) ms.emplace(u, set<int>());
      ms[u].insert(v);
      if (ms.count(v) == 0) ms.emplace(v, set<int>());
      ms[v].insert(u);
    }

    while(ms.size() > 2) {
      vector<pair<int, int>> vs;
      for (auto& it: ms) {
        if (it.second.size() <= 1) {
          vs.push_back(make_pair(it.first, *it.second.begin())); 
        }
      }
      for (const pair<int, int>& p : vs) {
        int u = p.first, v = p.second;
        ms.erase(u);
        ms[v].erase(u);
      }
    }

    vector<int> ans;
    for (const auto& it : ms) ans.push_back(it.first);
    return ans;
  }
};
