#include <set>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

set<pair<int ,int> > ms;

class MyCalendar {
 public:
  MyCalendar() {
    ms.clear(); 
  }
  
  bool book(int start, int end) {
    for (const pair<int, int>& p : ms) {
      int st = p.first, ed = p.second;
      if (!(st >= end || start >= ed)) return false;
    }
    ms.emplace(start, end);
    return true;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
