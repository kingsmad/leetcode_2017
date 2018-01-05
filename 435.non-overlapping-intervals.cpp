#include <algorithm>
#include <iostream>
#include <string>
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

class Solution {
 public:
  int eraseOverlapIntervals(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](Interval& s1, Interval& s2) {
      if (s1.start != s2.start) return s1.start < s2.start;
      return s1.end < s2.end;
    });

    int n = intervals.size();
    if (n == 0) return 0;
    int p = 0, q = 1, ans = 1;
    while(1) {
      if (q == n) break;
      if (intervals.at(q).start >= intervals.at(p).end) {
        p = q++;
        ++ans;
        continue;
      }
      if (intervals.at(q).end < intervals.at(p).end) {
        p = q++;
        continue;
      }
      ++q;
    }

    return n - ans;
  }
};
