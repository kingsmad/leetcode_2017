#include <vector>
#include <set>
#include <queue>

using namespace std;

class MedianFinder {
  priority_queue<int> lq;
  priority_queue<int, vector<int>, greater<int> > rq;
 public:
  /** initialize your data structure here. */
  MedianFinder() {
   lq = priority_queue<int>(); 
   rq = priority_queue<int, vector<int>, greater<int>>(); 
  }

  void addNum(int num) {
    if (!rq.empty() && rq.top() <= num) rq.push(num);
    else lq.push(num);

    maintain();
  }

  double findMedian() {
    double ans;
    if (lq.size() == rq.size()) {
      ans = (lq.top() + rq.top()) / 2.0;
    } else ans = lq.top();

    return ans;
  }

  void maintain() {
    while(lq.size() > rq.size() + 1) {
      int x = lq.top();
      lq.pop();
      rq.push(x);
    }

    while(rq.size() > lq.size()) {
      int x = rq.top();
      rq.pop();
      lq.push(x);
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
