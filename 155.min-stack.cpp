#include <bits/stdc++.h>

using namespace std;

class MinStack {
  stack<int> mq, tq;
public:
    /** initialize your data structure here. */
    MinStack() {
      mq = stack<int>();
      tq = stack<int>();
    }
    
    void push(int x) {
      tq.push(x);
      if (mq.empty() || mq.top() >= x) mq.push(x);
    }
    
    void pop() {
      int x = tq.top();
      tq.pop(); 

      if (mq.size() && mq.top() == x) mq.pop();
    }
    
    int top() {
      return tq.top(); 
    }
    
    int getMin() {
      return mq.top(); 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
