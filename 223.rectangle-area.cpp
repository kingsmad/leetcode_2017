#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    vector<int> v1 = {A, C, E, G};
    vector<int> v2 = {B, D, F, H};
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int v = (v1.at(2) - v1.at(1)) * (v2.at(2) - v2.at(1));
    if (min(C, G) <= max(A, E) || min(D, H) <= max(B, F)) v = 0;
    return (C-A) * (D-B) + (G-E) * (H-F) - v;
  }
};
