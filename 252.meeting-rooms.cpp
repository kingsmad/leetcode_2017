#include <bits/stdc++.h>
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
  bool canAttendMeetings(vector<Interval>& intervals) {
    auto cmp = [](const Interval& p1, const Interval& p2) {
      if (p1.start != p2.start) return p1.start < p2.start;
      return p1.end < p2.end;
    };
    sort(intervals.begin(), intervals.end(), cmp);
    for (int i=1; i<intervals.size(); ++i) {
      if (intervals[i].start < intervals[i-1].end) return false;
    }
    return true;
  }
};
