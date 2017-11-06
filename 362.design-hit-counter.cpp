#include <queue>
#include <set>
#include <vector>

using namespace std;

class HitCounter {
  priority_queue<int, vector<int>, greater<int> > mq;
 public:
  /** Initialize your data structure here. */
  HitCounter() {
    mq = priority_queue<int, vector<int>, greater<int>>();
  }

  /** Record a hit.
      @param timestamp - The current timestamp (in seconds granularity). */
  void hit(int timestamp) {
    mq.push(timestamp); 
    maintain(timestamp);
  }

  /** Return the number of hits in the past 5 minutes.
      @param timestamp - The current timestamp (in seconds granularity). */
  int getHits(int timestamp) {
    maintain(timestamp);
    return mq.size();
  }

  void maintain(int tsp) {
    int st = tsp - 300 + 1; 
    while(mq.size() && mq.top() < st) {
      mq.pop(); 
    }
  }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
