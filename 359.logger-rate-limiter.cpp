#include <bits/stdc++.h>
using namespace std;

class Logger {
  unordered_map<string, int> ms;

 public:
  /** Initialize your data structure here. */
  Logger() { ms.clear(); }

  /** Returns true if the message should be printed in the given timestamp,
     otherwise returns false. If this method returns false, the message will not
     be printed. The timestamp is in seconds granularity. */
  bool shouldPrintMessage(int timestamp, string message) {
    if (ms.count(message) && timestamp < ms[message]) return false;
    ms[message] = timestamp + 10;
    return true;
  }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
