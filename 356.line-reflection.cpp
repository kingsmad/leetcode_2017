#include <climits>
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

const double eps = 1e-6;

map<int, vector<int>> smp;

class Solution {
 public:
  bool isReflected(vector<pair<int, int>>& points) {
    if (points.empty()) return true;
    points.erase(unique(points.begin(), points.end()), points.end());
    smp.clear();
    for (pair<int, int>& p : points) {
      int x = p.first, y = p.second;
      if (smp.count(y) == 0) smp.emplace(y, vector<int>());
      smp[y].push_back(x);
    }

    for (auto& p : smp) {
      vector<int>& vc = p.second;
      sort(vc.begin(), vc.end()); 
    }

    int ax = INT_MIN;
    if (!Calc(smp.at(points.at(0).second), &ax)) return false;
    
    for (int i=1; i<points.size(); ++i) {
      int cx;
      if (!Calc(smp.at(points.at(i).second), &cx)) return false;
      if (abs(cx - ax) > eps) return false;
    }

    return true;
  }

  bool Calc(const vector<int>& vc, int* res) {
    int sum = vc.front() + vc.back();
    int p = 0, q = vc.size() - 1;
    while(p <= q) {
      if (sum != vc.at(p) + vc.at(q)) return false;
      ++p, --q;
    }

    *res = sum;
    return true;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  int n; scanf("%d", &n);
  vector<pair<int, int>> points;
  for (int i=0; i<n; ++i) {
    int d1 ,d2; scanf("%d%d", &d1, &d2);
    points.emplace_back(make_pair(d1, d2)); 
  }

  Solution sol;
  bool a = sol.isReflected(points);
  if (a) printf("YES\n");
  else printf("NO\n");

  return 0;
}

#endif
