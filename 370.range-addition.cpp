#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    const int n = length;   
    vector<int> diff(n+1, 0); 
    int base = 0;

    for (const vector<int>& v : updates) {
      int x = v.at(0), y = v.at(1), z = v.at(2);
      if (x > 0) diff[x-1] += z;
      if (x == 0) base += z;
      diff[y] -= z;
    }

    vector<int> a(n, 0);
    a[0] = base;
    for (int i=1; i<n; ++i) a[i] = diff[i-1] + a[i-1];
    

    return a;
  }
};
