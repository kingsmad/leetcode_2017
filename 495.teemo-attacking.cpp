#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if (timeSeries.empty()) return 0;
    int ans = 0, tm = timeSeries.front();
    for (int i=1; i<timeSeries.size(); ++i) {
      ans += min(timeSeries.at(i), tm + duration) - tm; 
      tm = timeSeries.at(i);
    }

    return ans + duration;
  }
};
