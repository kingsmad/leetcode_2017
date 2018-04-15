#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int dst = m + n -1, p = m-1, q = n-1;
    while(p >= 0 || q >= 0) {
      if (q < 0 || (p >= 0 && nums1[p] >= nums2[q])) {
        nums1[dst--] = nums1[p--];
      } else {
        nums1[dst--] = nums2[q--];
      }
    }
    return;
  }
};
