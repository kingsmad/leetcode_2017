#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
#endif

struct Node {
  int start, end, idx;
  Node(int d1, int d2, int d3) : start(d1), end(d2), idx(d3) { }
};

class Solution {
 public:
  vector<int> findRightInterval(vector<Interval>& intervals) {
    vector<Node> nodes;
    for (int i=0; i<intervals.size(); ++i) {
      const Interval& v = intervals.at(i);
      nodes.emplace_back(Node(v.start, v.end, i));
    }

    auto fn = [](const Node& p, const Node& q) {
      return p.start < q.start;
    };

    sort(nodes.begin(), nodes.end(), fn);

    vector<int> ans;
    for (const Interval& v : intervals) {
      int x = Calc(nodes, v.end);
      int val = (x == nodes.size()) ? -1 : nodes.at(x).idx;
      ans.push_back(val);
    }

    return ans;
  }

  int Calc(vector<Node>& nodes, int target) {
    int l = 0, r = nodes.size();
    while(l < r) {
      int md = (l+r) / 2;
      if (nodes.at(md).start < target) l = md + 1;
      else r = md;
    }

    return l;
  }
};
