#include <iostream>
#include <vector>
#include <string>

using namespace std;

// f(k) = f(k-1) + sum - n * A[n-k];
class Solution {
 public:
  int maxRotateFunction(vector<int>& A) {
    int sum = 0, n = A.size();
    for (int i=0; i<n; ++i) sum += A.at(i);

    int f = 0;
    for (int i=0; i<n; ++i) f += i * A.at(i);

    int ans = f;
    for (int k=1; k<n; ++k) {
      f = f + sum - n * A.at(n-k);
      ans = max(f, ans);
    }

    return ans;
  }
};
