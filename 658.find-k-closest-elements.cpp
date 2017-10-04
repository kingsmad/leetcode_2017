#include <math.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Solution {
  public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      int n = arr.size();
      int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
      int l = pos - 1, r = pos;
      vector<int> ans;
      while(k--) {
        if (l>=0 && l<n && r>=0 && r<n) {
          if (abs(arr.at(l) - x) <= abs(arr.at(r) - x)) {
            ans.push_back(arr.at(l--));
          } else {
            ans.push_back(arr.at(r++));
          }
        } else if (l >= 0 && l<n) {
          ans.push_back(arr.at(l--));
        } else if (r >= 0 && r < n) {
          ans.push_back(arr.at(r++));
        }
      }

      sort(ans.begin(), ans.end());
      return ans;

    }
};
