#include <algorithm>
#include <vector>
#include <string>

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
  vector<Interval> merge(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), 
        [](const Interval& p1, const Interval& p2) {
          return p1.start < p2.start;
    });

    int n = intervals.size();
    vector<Interval> ans;
    for (int i=0; i<n; ) {
      int q = i + 1; 
      int mx = intervals.at(i).end;
      while(q < n && intervals.at(q).start <= mx) {
        mx = max(mx, intervals.at(q).end);
        ++q;
      }
      ans.push_back(Interval(intervals.at(i).start, mx));
      i = q;
    }
   
    return ans;
  }
};
