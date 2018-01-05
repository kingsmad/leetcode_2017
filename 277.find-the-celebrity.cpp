#include <iostream>
#include <vector>

// Forward declaration of the knows API.
bool knows(int a, int b);
using namespace std;

class Solution {
 public:
  int findCelebrity(int n) {
    vector<int> nums;
    for (int i=0; i<n; ++i) nums.push_back(i);
    
    while(nums.size() > 1) {
      int n = nums.size();
      int p = nums.at(n-2), q = nums.at(n-1);
      nums.pop_back();
      if (knows(p, q)) {
        nums.pop_back();
        nums.push_back(q);
      }
    }

    int target = nums.front();

    for (int i=0; i<n; ++i) if (i != target && !knows(i, target)) return -1;
    for (int i=0; i<n; ++i) if (i != target && knows(target, i)) return -1;
    return target;
  }
};
