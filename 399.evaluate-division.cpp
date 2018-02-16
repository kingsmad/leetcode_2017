#include <bits/stdc++.h>
// solution from http://blog.csdn.net/qq508618087/article/details/52560983

using namespace std;
const int maxn = 110;

class Solution {
 public:
  vector<double> calcEquation(vector<pair<string, string>> equations,
                              vector<double>& values,
                              vector<pair<string, string>> queries) {
    unordered_map<string, unordered_map<string, double>> dis;
    for (int i = 0; i < equations.size(); i++) {
      dis[equations[i].first][equations[i].second] = values[i];
      dis[equations[i].second][equations[i].first] = 1 / values[i];
    }
    for (auto val : dis) dis[val.first][val.first] = 1;
    for (auto k : dis) {
      for (auto i : dis)
        for (auto j : dis)
          if (dis[k.first].count(j.first)
              && dis[i.first].count(k.first))
            dis[i.first][j.first] =
                dis[i.first][k.first] * dis[k.first][j.first];
    }
    vector<double> ans;
    for (auto val : queries)
      ans.push_back(
          dis[val.first].count(val.second) ? dis[val.first][val.second] : -1);
    return ans;
  }
};
