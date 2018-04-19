#include <bits/stdc++.h>
using namespace std;

class MyStack {
  queue<int> mq_;
public:
    /** Initialize your data structure here. */
    MyStack() {
      mq_ = queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
      mq_.push(x);
      int n = mq_.size();
      for (int i=0; i+1<n; ++i) {
        int v = mq_.front();
        mq_.pop();
        mq_.push(v);
      }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
      int x = mq_.front();    
      mq_.pop();
      return x;
    }

    
    /** Get the top element. */
    int top() {
      return mq_.front(); 
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
      return mq_.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
