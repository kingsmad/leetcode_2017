#include <bits/stdc++.h>
using namespace std;

class MyQueue {
  stack<int> ms[2];
  int cur = 0;

 public:
  /** Initialize your data structure here. */
  MyQueue() {
    ms[0] = stack<int>();
    ms[1] = stack<int>();
    cur = 0;
  }

  /** Push element x to the back of queue. */
  void push(int x) { ms[cur].push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (ms[!cur].empty()) transfer();
    int x = ms[!cur].top();
    ms[!cur].pop();
    return x;
  }

  /** Get the front element. */
  int peek() {
    if (ms[!cur].empty()) transfer();
    return ms[!cur].top();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return ms[cur].empty() && ms[!cur].empty(); }

  void transfer() {
    while (ms[cur].size()) {
      int x = ms[cur].top();
      ms[cur].pop();
      ms[!cur].push(x);
    }
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
