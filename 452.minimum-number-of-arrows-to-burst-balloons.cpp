#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int findMinArrowShots(vector<pair<int, int>>& points) {
    if (points.empty()) return 0;
    sort(points.begin(), points.end());
    int n = points.size();
    int cnt = 1; 
    int ed = points[0].second;
    for (int i=0; i<n;++i ) {
      if (points[i].first <= ed) {
        ed = min(ed, points[i].second);
      } else {
        ++cnt; 
        ed = points[i].second;
      }
    }
    
    return cnt;
  }
};
