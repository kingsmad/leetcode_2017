#include <bits/stdc++.h>
using namespace std;

class MaxStack {
 private:
   int sz = 0;
   map<int, int> sid2val;
   stack<int> msk;
   function<bool(int, int)> cmp_;
   set<int, function<bool(int, int)>> ms;
public:
  /** initialize your data structure here. */
  MaxStack() {
    cmp_ = [&](int x, int y) { return sid2val[x] < sid2val[y];};
    sid2val.clear();  
    msk.clear();
    ms = set<int, function<bool(int, int)>>(cmp_);
    sz = 0;
  }

  void push(int x) {
    int p = sz++; 
    sid2val.emplace(p, x);
    msk.push(p);
  }

  int pop() {
    while(sid2val.count(msk.top()) == 0) msk.pop();
    int v = sid2val[msk.top()];
    sid2val.erase(msk.top());
    return v;
  }

  int top() {
    while(sid2val.count(msk.top()) == 0) msk.pop();
    return sid2val[msk.top()]; 
  }

  int peekMax() {
    auto it = ms.end(); --it;
    while(sid2val.count(*it) == 0) --it;
    int v = *it;
    ms.erase(it, ms.end());
    return v;
  }

  int popMax() {
    auto it = ms.end(); --it;
    while(sid2val.count(*it) == 0) --it;
    int v = *it;
    sid2val.erase(v);
    ms.erase(it, ms.end());   
    return v;
  }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
