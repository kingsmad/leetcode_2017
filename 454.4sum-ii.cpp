#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int ans = 0; 
    map<int, int> ms1, ms2;
    for (int a : A) for (int b: B) ++ms1[a+b];
    for (int c : C) for (int d: D) ++ms2[c+d];

    for (auto it : ms1) {
      int key = it.first, v = it.second;
      if (ms2.count(-key) > 0) {
        ans += v * ms2[-key]; 
      }
    }

    return ans;
  }
};
