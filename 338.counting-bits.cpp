#include <vector>
using namespace std;

inline int lowbit(int x) { return x & (-x);}

class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> ans;
    for (int i=0; i<=num; ++i) ans.push_back(count(i));
    return ans;
  }

  int count(int x) {
    int ans = 0;
    while(lowbit(x) > 0) {
      ++ans;
      x -= lowbit(x);
    }
    return ans;
  }

};
