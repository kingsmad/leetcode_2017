#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 2e4 + 10;
int x[maxn], y[maxn];

class Solution {
 public:
   void Parse(const string & s, int* x, int* y) {
     sscanf(s.c_str(), "%d:%d", x, y);
     return;
   }

   int Calc(int p, int q) {
     int ans = (x[q] - x[p]) * 60 + (y[q] - y[p]);
     if (ans < 0 ) ans += 24 * 60;
     return min(ans, 24 * 60 - ans);
   }

  int findMinDifference(vector<string>& timePoints) {
    int n = timePoints.size();
    for (int i=0; i<n; ++i) Parse(timePoints.at(i), x+i, y+i);

    vector<int> sid; for (int i=0; i<n; ++i) sid.push_back(i);

    sort(sid.begin(), sid.end(), [&](int p, int q) {
      if (x[p] != x[q]) return x[p] < x[q]; 
      return y[p] < y[q];
    });
    
    int ans = 25 * 60;

    for (int z=0; z<n; ++z) {
      ans = min(ans, Calc(sid[z], sid[(z+1)%n]));
    }

    return ans;
  }

};
