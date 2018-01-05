#include <map>
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
  int minMeetingRooms(vector<Interval>& intervals) {
    map<int, int> ms;
    for (auto& p : intervals) {
      ++ms[p.start];
      --ms[p.end]; 
    }
    int sum = 0, ans = 0;
    for (auto& p : ms) {
      sum += p.second;
      ans = max(ans, sum);
    }

    return ans;
  }
};
