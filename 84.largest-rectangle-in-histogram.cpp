#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    stack<int> ms;
    int n = heights.size();

    vector<int> lans(n, 0);
    vector<int> rans(n, 0);

    for (int i = 0; i < n; ++i) {
      while (!ms.empty() && heights.at(ms.top()) >= heights.at(i)) { ms.pop(); }
      int v = 0;
      if (ms.size()) v = (i - ms.top()) * heights.at(i);
      else v = (i+1) * heights.at(i);

      lans[i] = v;
      ms.push(i);
    }

    ms = stack<int>();
    for (int i=n-1; i>=0; --i) {
      while(!ms.empty() && heights.at(ms.top()) >= heights.at(i)) { ms.pop();}
      int v = 0;
      if (ms.size()) v = (ms.top() - i) * heights.at(i);
      else v = (n - i) * heights.at(i);

      rans[i] = v;
      ms.push(i);
    }

    int ans = 0;
    for (int i=0; i<n; ++i) ans = max(ans, lans[i] + rans[i] - heights.at(i));

    return ans;

  }
};
