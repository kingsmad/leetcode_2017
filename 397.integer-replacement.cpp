#include <map>
#include <queue>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

class Solution {
 public:
  int integerReplacement(int n) {
    queue<ll> mq;
    map<ll, ll> ms;
    mq.push(n);
    ms[n] = 0;
    while(1) {
      ll x = mq.front();
      mq.pop();
      if (x == 1) return ms.at(1);
      if (x & 1) { 
        if (ms.count(x-1) == 0) {
          ms[x-1] = ms.at(x) + 1;
          mq.push(x-1);
        }
        if (ms.count(x+1) == 0) {
          ms[x+1] = ms.at(x) + 1;
          mq.push(x+1);
        }
      } else {
        if (ms.count(x/2) == 0) {
          ms[x/2] = ms.at(x) + 1;
          mq.push(x/2);
        }
      }
    }
    return -1;
  }
};
