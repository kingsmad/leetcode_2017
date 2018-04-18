#include <bits/stdc++.h>
using namespace std;
class TwoSum {
  unordered_multiset<int> nums_;
 public:
  /** Initialize your data structure here. */
  TwoSum() { nums_.clear(); }

  /** Add the number to an internal data structure.. */
  void add(int number) {
    nums_.insert(number);
  }

  /** Find if there exists any pair of numbers which sum is equal to the value.
   */
  bool find(int value) {
    for (int i : nums_) {
      int v = (i == value - i) ? 2 : 1;
      if (nums_.count(value -i ) >= v) return true;
    }
    return false;
  }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
