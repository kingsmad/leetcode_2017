#include <bits/stdc++.h>
using namespace std;

class MovingAverage {
  deque<int> mq;
  double tot;
  int sz;

 public:
  /** Initialize your data structure here. */
  MovingAverage(int size) {
    mq.clear();
    tot = 0;
    sz = size;
  }

  double next(int val) {
    mq.push_back(val);
    tot += val;
    while (mq.size() > sz) { 
      tot -= mq.front();
      mq.pop_front();
    }
    return tot / mq.size();
  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
