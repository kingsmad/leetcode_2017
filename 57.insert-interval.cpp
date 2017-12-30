#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#ifdef ROACH_ONLINE_JUDGE
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
#endif

class Solution {
 public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    intervals.push_back(newInterval);
    auto fn = [](const Interval& p1, const Interval& p2) {
      if (p1.start != p2.start) return p1.start < p2.start;
      return p1.end < p2.end;
    };
    sort(intervals.begin(), intervals.end(), fn);

    vector<Interval> ans;

    int n = intervals.size();
    for (int i=0; i<n; ) {
      int p = i + 1; 
      int st = intervals.at(i).start;
      int ed = intervals.at(i).end;
      while(1) {
        if (p == n) break;
        if (intervals.at(p).start > ed) break;
        ed = max(ed, intervals.at(p).end);
        ++p;
      }
      
      ans.push_back(Interval(st ,ed));
      i = p;
    }

    return ans;
  }
};
