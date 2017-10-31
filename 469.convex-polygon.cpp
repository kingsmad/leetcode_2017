#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 2e4 + 10;
using ll = long long;

struct KPoint {
  int x, y;
  KPoint(int x=0, int y=0) : x(x), y(y) { }
};

bool operator < (const KPoint& p1, const KPoint& p2) {
  if (p1.x != p2.x) return p1.x < p2.x;
  return p1.y < p2.y;
}

bool operator == (const KPoint& p1, const KPoint& p2) {
  return p1.x == p2.x && p1.y == p2.y;
}

typedef KPoint Vector;

Vector operator - (const KPoint& p1, const KPoint& p2) {
  return (KPoint){p1.x - p2.x, p1.y-p2.y};
}

inline ll Cross(Vector a, Vector b) { return a.x * b.y - b.x * a.y;}

vector<KPoint> convexHull(vector<KPoint>& p) {
  int n = p.size();
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());

  int m = 0;
  vector<KPoint> ch(n+1);
  for (int i=0; i<n; ++i) {
    while(m > 1 && Cross(ch[m-1] - ch[m-2], p[i] - ch[m-2]) < 0) --m;
    ch[m++] = p[i];
  }

  int k = m;
  for (int i=n-2; i>=0; --i) {
    while(m > k && Cross(ch[m-1]-ch[m-2], p[i] - ch[m-2]) < 0) --m;
    ch[m++] = p[i];
  }

  if (n > 1) m--;
  ch.resize(m);
  return ch;
}

class Solution {
 public:
  bool isConvex(vector<vector<int>>& points) {
    vector<KPoint> mp;
    for (const vector<int>& v : points) {
      int x = v.at(0), y = v.at(1);
      mp.push_back((KPoint){x, y});
    }

    return convexHull(mp).size() == points.size();
  }
};
