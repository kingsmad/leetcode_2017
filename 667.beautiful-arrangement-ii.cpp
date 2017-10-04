#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> constructArray(int n, int k) {
    int p = 1, q = n;
    vector<int> ans;
    while (p <= q) {
      if (k % 2 == 0) ans.push_back(p++);
      else ans.push_back(q--);
      if (k > 1) --k;
    }

    return ans;
  }
};
