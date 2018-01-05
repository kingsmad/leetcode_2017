#include <set>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

set<pair<int ,int> > ms;
set<pair<int, int> > ms1;

class MyCalendarTwo {
 public:
  MyCalendarTwo() {
    ms.clear(); 
    ms1.clear();
  }
  
  bool book(int start, int end) {
    int cnt = 0; 
    for (const pair<int, int>& p : ms1) {
      int st = p.first, ed = p.second;
      if (!(st >= end || start >= ed)) {
        return false;
      }
    }

    vector<pair<int, int>> viter(ms.begin(), ms.end());
    for (const pair<int, int>& p : viter) {
      int st = p.first, ed = p.second;
      if (!(st >= end || start >= ed)) {
        ms1.emplace(max(st, start), min(ed, end));
        ms.erase(p);
        ms.emplace(min(st, start), max(st, start));
        ms.emplace(min(ed, end), max(ed, end));
      }
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
