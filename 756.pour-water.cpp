#include <vector>
#include <string>
#include <iostream>

using namespace std;
int n;

class Solution {
 public:
  vector<int> pourWater(vector<int>& heights, int V, int K) {
    vector<int> water = heights;
    n = water.size(); 
    int stage = water.at(K);

    while(V--) {
      int p = K;
      while(p-1 >= 0 && water.at(p-1) <= water.at(p)) --p;
      while(p < K && water.at(p) == water.at(p+1)) ++p;
      while(p+1 < n && water.at(p+1) <= water.at(p)) ++p;
      while(p > K && water.at(p) == water.at(p-1)) --p;
      ++water[p];
    }

    return water;
  }
};
