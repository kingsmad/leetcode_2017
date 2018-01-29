#include <assert.h>
#include <set>
#include <algorithm>
#include <climits>
#include <cstring>
#include <unordered_map>
#include <iostream>
#include <vector>
#define lc (o<<1)
#define rc (o<<1|1)

// note: remember the oeration of 'set the range with at least height h' is 
// and addv action!

using namespace std;
using ll = long long;
const int maxnode = 4e5 + 10;

struct SegmentTree {
  int lv[maxnode], rv[maxnode], maxv[maxnode], addv[maxnode];
  void init() {
    memset(lv, 0, sizeof(lv));
    memset(rv, 0, sizeof(rv));
    memset(maxv, 0, sizeof(maxv));
    memset(addv, -1, sizeof(addv));
  }

  void build(int o, int l, int r) {
    lv[o] = l, rv[o] = r;
    if (l == r) {
      maxv[o] = addv[o] = 0;
      return;
    }
    
    maxv[o] = 0;
    addv[o] = -1;
    int md = (l+r) / 2;
    build(lc, l, md);
    build(rc, md+1, r);
    maintain(o);
  }

  void update_max(int o, int ql, int qr, int qv) {
    int l = lv[o], r = rv[o];
    assert(!(l > qr || r < ql));

    if (ql <= l && qr >= r) {
      addv[o] = max(addv[o], qv);
    } else {
      pushdown(o);
      int md = (l+r) / 2;
      if (ql <= md) update_max(lc, ql, qr, qv); else maintain(lc);
      if (qr > md) update_max(rc, ql, qr, qv); else maintain(rc);
    }

    maintain(o);
  }
  
  int query_max(int o, int ql, int qr, int ad) {
    int l = lv[o], r = rv[o];
    assert(!(l > qr || r < ql));
    if (ql <= l && qr >= r) {
      return max(maxv[o], ad);
    } else {
      int md = (l+r) / 2;
      int ans = 0;
      if (ql <= md) ans = max(ans, query_max(lc, ql, qr, max(ad, addv[o])));
      if (qr > md ) ans = max(ans, query_max(rc, ql, qr, max(ad, addv[o])));
      return ans;
    }
  }

  // push info to children
  void pushdown(int o) {
    int l = lv[o], r = rv[o];
    if (addv[o] >= 0) {
      addv[lc] = max(addv[lc], addv[o]);
      addv[rc] = max(addv[rc], addv[o]);
      addv[o] = -1;
    }
  }

  // addv and setv are settled down, and info on children is also settle down
  // we recaculated information on node o
  void maintain(int o) {
    if (rv[o] > lv[o]) maxv[o] = max(maxv[lc], maxv[rc]);
    if (addv[o] >= 0) maxv[o] = max(maxv[o], addv[o]);
  }
} stree;

class Solution {
  unordered_map<int, int> msid;
  int sid = 1;
  
 public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    msid.clear();
    sid = 1;
    //stree.init();

    // get sids
    vector<int> vx;
    for (const vector<int>& v : buildings) {
      vx.push_back(v.at(0));
      vx.push_back(v.at(1));
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    for (int d : vx) getsid(d);
    stree.build(1, 0, sid+2);
  
    for (const vector<int>& vc : buildings) {
      stree.update_max(1, getsid(vc.at(0)), getsid(vc.at(1)), vc.at(2));
    }

    vector<pair<int, int>> ans;

    int pre_h = -1;
    for (int d : vx) {
      int c = stree.query_max(1, getsid(d)+1, getsid(d)+1, 0);
      if (c == pre_h) continue;
      pre_h = c;
      ans.push_back(make_pair(d, c));
    }
    

    return ans;
  }

  int getsid(int x) {
    if (!msid.count(x)) { msid.emplace(x, sid); sid+=2;}
    return msid.at(x);
    return x;
  }
};

#ifdef ROACH_ONLINE_JUDGE
int main(int argc, char** argv) {
  freopen("in.txt", "r", stdin);
  int n; scanf("%d", &n);
  vector<vector<int> > buildings(n);
  for (int i=0; i<n; ++i) {
    int d1, d2, d3; scanf("%d%d%d", &d1, &d2, &d3);
    buildings[i] = {d1, d2, d3};
  }

  Solution sol;
  vector<pair<int, int> > ans = sol.getSkyline(buildings);
  for (pair<int, int>& p : ans) { printf("%d %d\n", p.first, p.second); }

  return 0;
}
#endif
