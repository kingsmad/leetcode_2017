#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class PhoneDirectory {
  set<int> ms, idle;
  int sz = 0, cap = 0;
 public:
  /** Initialize your data structure here
      @param maxNumbers - The maximum numbers that can be stored in the phone
     directory. */
  PhoneDirectory(int maxNumbers) {
    cap = maxNumbers;
  }

  /** Provide a number which is not assigned to anyone.
      @return - Return an available number. Return -1 if none is available. */
  int get() {
    int ans = -1;
    if (idle.size()) {
      ans = *idle.begin(); 
      idle.erase(idle.begin());
    } else {
      if (sz == cap) return -1;
      ans = sz++;
    }

    ms.insert(ans);
    return ans;
  }

  /** Check if a number is available or not. */
  bool check(int number) {
    return ms.count(number) == 0;
  }

  /** Recycle or release a number. */
  void release(int number) {
    if (ms.count(number) == 0) return;
    ms.erase(number);
    idle.insert(number);
  }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
