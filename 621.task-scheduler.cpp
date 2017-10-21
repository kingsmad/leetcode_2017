#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> mmp;
    unordered_map<char, int> lock;
    for (char c : tasks) {
      ++mmp[c];
      lock[c] = 0;
    }

    int ans = 0;
    while (!mmp.empty()) {
      int tm = INT_MAX;
      for (auto it = lock.begin(); it != lock.end(); ++it) {
        tm = min(tm, it->second);
      }
      ans += tm;
      for (auto it = lock.begin(); it != lock.end(); ++it) { it->second -= tm; }

      int s = 0;
      char x = -1;
      for (auto it = mmp.begin(); it != mmp.end(); ++it) {
        char c = it->first;
        if (lock[c] > 0) {
          --lock[c];
          continue;
        }
        if (mmp[c] > s) {
          x = c;
          s = mmp[c];
        }
      }

      if (x == -1) break;
      ++ans;
      lock[x] = n;
      if (--mmp[x] == 0) {
        mmp.erase(x);
        lock.erase(x);
      }
    }

    return ans;
  }
};
