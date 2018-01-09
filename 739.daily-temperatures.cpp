#include <stack>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> ms;
    for (int i=0; i<n; ++i) {
      while(1) {
        if (ms.empty()) break;
        int x = ms.top();
        if (temperatures.at(x) < temperatures.at(i)) {
          ans[x] = i - x;
          ms.pop(); 
        } else {
          break;
        }
      }
      ms.push(i);
    }
    return ans;
  }
};
